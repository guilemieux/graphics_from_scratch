#ifndef _COLOR_H_
#define _COLOR_H_

// Hexadecimal values of common colors
#define WHITE   0xFFFFFF
#define SILVER  0xC0C0C0
#define GRAY    0x808080
#define BLACK   0x000000
#define RED     0xFF0000
#define MAROON  0x800000
#define YELLOW  0xFFFF00
#define OLIVE   0x808000
#define LIME    0x00FF00
#define GREEN   0x008000
#define AQUA    0x00FFFF
#define TEAL    0x008080
#define BLUE    0x0000FF
#define NAVY    0x000080
#define FUCHSIA 0xFF00FF
#define PURPLE  0x800080

/**
 * Structure holding the information necessary to represent a color.
 * A color is represented using an rgb triple. That is, it holds a value
 * for the intensity of red green and blue for the color. The intensity of a
 * color ranges between 0 and 255 (unsigned char).
 * 
 * For example, the color black is represented by the triple (0, 0, 0) and the
 * color white is represented as the triple (255, 255, 255).
 */
struct color {
    unsigned char r; // Intensity of red
    unsigned char g; // Intensity of green
    unsigned char b; // Intensity of blue
};

/** Helper function for a more readable way to create a color struct. */
extern struct color rgb(unsigned char r, unsigned char g, unsigned char b);

/**
 * Returns a color structure based on its hexadecimal representation. Since
 * the intensity of reg, green and blue of a color is an integer between 0 and
 * 255, we can represent that value with 8 bits. A sequence of 8 bits
 * can be expressed as a two digit hexadecimal number. We want to represent
 * three values between 0 and 255 so we use a six digit hexadecimal number.
 * The first two digits holds the intensity for red, the second two for green
 * and the last two for blue.
 * 
 *     Hexadecimal number:  0x XX      XX      XX
 *                             RED    GREEN   BLUE
 * 
 * For example, 0xF0FF0F would correspond to the rgb triple (240, 255, 15)
 * because 0xF0 = 240, 0xFF = 255 and 0x0F = 15. This function is most useful
 * when used with the defined common colors in this file (e.g. get_color(AQUA))
 * 
 * @param hex_color: The hexadecimal representation of the color.
 * @return: A color struct representing the hexadecimal value.
 */
extern struct color get_color(int hex_color);

/**
 * Compares 2 colors using their hexadecimal representation. The function
 * returns a negative number if c1 < c2, 0 if c1 = c2 and a positive number
 * if c1 > c2.
 * @param c1: The first color to compare.
 * @param c2: The second color to compare.
 * @return: The difference between the hex representation of c1 and c2.
 */
extern int compare_color(struct color c1, struct color c2);

#endif
