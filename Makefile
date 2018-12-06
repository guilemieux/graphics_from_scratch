CC = gcc
CFLAGS = -g -Wall

INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

objects = main.o scene.o triangle.o vector.o matrix.o
OBJS = $(addprefix $(OBJ_DIR)/, $(objects))

# Build binary output
main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BIN_DIR)/$@

# Compilation of object files
MAIN_DEPS = $(addprefix $(INC_DIR)/, scene.h triangle.h vector.h)
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(MAIN_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

SCENE_DEPS = $(addprefix $(INC_DIR)/, matrix.h scene.h triangle.h vector.h)
$(OBJ_DIR)/scene.o: $(SRC_DIR)/scene.c $(SCENE_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

TRIANGLE_DEPS = $(addprefix $(INC_DIR)/, triangle.h vector.h)
$(OBJ_DIR)/triangle.o: $(SRC_DIR)/triangle.c $(TRIANGLE_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/vector.o: $(SRC_DIR)/vector.c $(INC_DIR)/vector.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/matrix.o: $(SRC_DIR)/matrix.c $(INC_DIR)/matrix.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clear the directories obj/ and bin/
clean:
	rm -f obj/*.o bin/*