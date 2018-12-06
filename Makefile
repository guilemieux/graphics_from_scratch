CC = gcc
CFLAGS = -g -Wall

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

objects = main.o scene.o triangle.o vector.o matrix.o
OBJS = $(addprefix $(OBJ_DIR)/, $(objects))

# Binary output
main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$@


$(OBJ_DIR)/main.o: $(addprefix $(INC_DIR)/, scene.h triangle.h vector.h)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $@

$(OBJ_DIR)/scene.o: $(addprefix $(INC_DIR)/, matrix.h scene.h triangle.h vector.h)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/scene.c -o $@

$(OBJ_DIR)/triangle.o: $(addprefix $(INC_DIR)/, triangle.h vector.h)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/triangle.c -o $@

$(OBJ_DIR)/vector.o: $(INC_DIR)/vector.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/vector.c -o $@

$(OBJ_DIR)/matrix.o: $(INC_DIR)/matrix.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/matrix.c -o $@


# default: main

# main: main.o scene.o triangle.o vector.o
# 	$(CC) $(CFLAGS) -o bin/main obj/main.o obj/scene.o obj/triangle.o obj/vector.o

# main.o: src/main.c src/scene.h src/vector.h src/triangle.c
# 	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

# test: vector_test triangle_test
# 	@echo ""
# 	@echo "Running Vector Tests"
# 	@bin/vector_test
# 	@echo ""
# 	@echo "Running Triangle Tests"
# 	@bin/triangle_test

# # Triangle_test
# triangle_test: triangle_test.o triangle.o vector.o
# 	$(CC) $(CFLAGS) -o bin/triangle_test obj/triangle_test.o obj/triangle.o obj/vector.o
# triangle_test.o: tests/triangle_test.c src/triangle.h
# 	$(CC) $(CFLAGS) -c tests/triangle_test.c -o obj/triangle_test.o

# # Vector_test
# vector_test: vector_test.o vector.o
# 	$(CC) $(CFLAGS) -o bin/vector_test obj/vector_test.o obj/vector.o
# vector_test.o: tests/vector_test.c src/vector.h
# 	$(CC) $(CFLAGS) -c tests/vector_test.c -o obj/vector_test.o

# # Includes
# bitmap.o: src/bitmap.c src/bitmap.h
# 	$(CC) $(CFLAGS) -c src/bitmap.c -o obj/bitmap.o

# bmp.o: src/bmp.c src/bmp.h
# 	$(CC) $(CFLAGS) -c src/bmp.c -o obj/bmp.o

# pixel.o: src/pixel.c src/pixel.h
# 	$(CC) $(CFLAGS) -c src/pixel.c -o obj/pixel.o

# scene.o: src/scene.c src/scene.h matrix.o
# 	$(CC) $(CFLAGS) -c src/scene.c -o obj/scene.o

# matrix.o: src/matrix.c src/matrix.h
# 	$(CC) $(CFLAGS) -c src/matrix.c -o obj/matrix.o

# triangle.o: src/triangle.c src/triangle.h
# 	$(CC) $(CFLAGS) -c src/triangle.c -o obj/triangle.o

# vector.o: src/vector.c src/vector.h
# 	$(CC) $(CFLAGS) -c src/vector.c -o obj/vector.o

# clean:
# 	rm -f obj/*.o bin/*

src = $(wildcard src/*.c)
obj = $(src:.c=.o)

LDFLAGS = -g -Wall

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog