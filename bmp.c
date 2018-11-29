#include <stdio.h>
#include <stdint.h>
#include "bmp.h"
#include "bitmap.h"

#define BMP_MAGIC_ID 0x4D42
#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8
#define BMP_HEADER_SIZE 14
#define DIB_HEADER_SIZE 40
#define COMPRESSION 0
#define PRINT_RESOLUTION 2835

struct bmp_header {
    uint16_t magic;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
};

struct dib_header {
    uint32_t size;
    uint32_t width;
    uint32_t height;
    uint16_t color_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t bitmap_data_size;
    uint32_t hor_print_resolution;
    uint32_t ver_print_resolution;
    uint32_t colors_in_palette;
    uint32_t important_colors;
};

/************************************************
 * HELPER METHODS
 ***********************************************/
void write_bmp_header(struct bmp_header *bmp_h, FILE *fp)
{
    fwrite(&bmp_h->magic, sizeof(bmp_h->magic), 1, fp);
    fwrite(&bmp_h->size, sizeof(bmp_h->size), 1, fp);
    fwrite(&bmp_h->reserved1, sizeof(bmp_h->reserved1), 1, fp);
    fwrite(&bmp_h->reserved2, sizeof(bmp_h->reserved2), 1, fp);
    fwrite(&bmp_h->offset, sizeof(bmp_h->offset), 1, fp);
}

void write_dib_header(struct dib_header *dib_h, FILE *fp)
{
    fwrite(&dib_h->size, sizeof(dib_h->size), 1, fp);
    fwrite(&dib_h->width, sizeof(dib_h->width), 1, fp);
    fwrite(&dib_h->height, sizeof(dib_h->height), 1, fp);
    fwrite(&dib_h->color_planes, sizeof(dib_h->color_planes), 1, fp);
    fwrite(&dib_h->bits_per_pixel, sizeof(dib_h->bits_per_pixel), 1, fp);
    fwrite(&dib_h->compression, sizeof(dib_h->compression), 1, fp);
    fwrite(&dib_h->bitmap_data_size, sizeof(dib_h->bitmap_data_size), 1, fp);
    fwrite(&dib_h->hor_print_resolution, sizeof(dib_h->hor_print_resolution), 1, fp);
    fwrite(&dib_h->ver_print_resolution, sizeof(dib_h->ver_print_resolution), 1, fp);
    fwrite(&dib_h->colors_in_palette, sizeof(dib_h->colors_in_palette), 1, fp);
    fwrite(&dib_h->important_colors, sizeof(dib_h->important_colors), 1, fp);
}

void write_pixel(Pixel_t pixel, FILE *fp)
{
    fputc(Pixel_get_blue(pixel), fp);
    fputc(Pixel_get_green(pixel), fp);
    fputc(Pixel_get_red(pixel), fp);
}

void write_row_padding(int padding_size, FILE *fp)
{
    for (int i = 0; i < padding_size; i++)
        fputc(0, fp);
}

/*  */
void write_pixel_array(Bitmap_t bitmap, FILE *fp)
{
    int padding_size = Bitmap_get_width(bitmap) % 4;
    for (int row = Bitmap_get_height(bitmap) - 1; row >= 0; row--) {
        for (int col = 0; col < Bitmap_get_width(bitmap); col++) {
            write_pixel(Bitmap_get_pixel(bitmap, row, col), fp);
        }

        // Add padding to the end of the row
        for (int i = 0; i < padding_size; i++) fputc(0, fp);
    }
}

/************************************************
 * INTERFACE IMPLEMENTATIONS
 ***********************************************/
void save_to_bmp(Bitmap_t bitmap, char *file_name)
{
    int bits_per_pixel = BYTES_PER_PIXEL * BITS_PER_BYTE;
    int row_size = ((bits_per_pixel * Bitmap_get_width(bitmap) + 31) / 32) * 4;
    int pixel_array_size = row_size * Bitmap_get_height(bitmap);
    
    // Create bmp_header
    struct bmp_header bmp_h;
    bmp_h.magic = BMP_MAGIC_ID;
    bmp_h.size = BMP_HEADER_SIZE + DIB_HEADER_SIZE + pixel_array_size;
    bmp_h.reserved1 = 0;
    bmp_h.reserved2 = 0;
    bmp_h.offset = BMP_HEADER_SIZE + DIB_HEADER_SIZE;

    // Create dib_header
    struct dib_header dib_h;
    dib_h.size = DIB_HEADER_SIZE;
    dib_h.width = Bitmap_get_width(bitmap);
    dib_h.height = Bitmap_get_height(bitmap);
    dib_h.color_planes = 1;
    dib_h.bits_per_pixel = bits_per_pixel;
    dib_h.compression = COMPRESSION;
    dib_h.bitmap_data_size = pixel_array_size;
    dib_h.hor_print_resolution = PRINT_RESOLUTION;
    dib_h.ver_print_resolution = PRINT_RESOLUTION;
    dib_h.colors_in_palette = 0;
    dib_h.important_colors = 0;

    // Write to file
    FILE *bmp_file = fopen(file_name, "wb");
    write_bmp_header(&bmp_h, bmp_file);
    write_dib_header(&dib_h, bmp_file);
    write_pixel_array(bitmap, bmp_file);
    fclose(bmp_file);
}