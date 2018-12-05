test: vector_test triangle_test
	@echo ""
	@echo "Running Vector Tests"
	@bin/vector_test
	@echo ""
	@echo "Running Triangle Tests"
	@bin/triangle_test

# Triangle_test
triangle_test: triangle_test.o triangle.o vector.o
	gcc -o bin/triangle_test obj/triangle_test.o obj/triangle.o obj/vector.o
triangle_test.o: tests/triangle_test.c src/triangle.h
	gcc -c tests/triangle_test.c -o obj/triangle_test.o

# Vector_test
vector_test: vector_test.o vector.o
	gcc -o bin/vector_test obj/vector_test.o obj/vector.o
vector_test.o: tests/vector_test.c src/vector.h
	gcc -c tests/vector_test.c -o obj/vector_test.o

# Includes
bitmap.o: src/bitmap.c src/bitmap.h
	gcc -c src/bitmap.c -o obj/bitmap.o
bmp.o: src/bmp.c src/bmp.h
	gcc -c src/bmp.c -o obj/bmp.o
pixel.o: src/pixel.c src/pixel.h
	gcc -c src/pixel.c -o obj/pixel.o
scene.o: src/scene.c src/scene.h
	gcc -c src/scene.c src/scene.h
triangle.o: src/triangle.c src/triangle.h
	gcc -c src/triangle.c -o obj/triangle.o
vector.o: src/vector.c src/vector.h
	gcc -c src/vector.c -o obj/vector.o

clean:
	rm -f obj/*.o bin/*