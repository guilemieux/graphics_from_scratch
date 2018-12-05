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
vector.o: src/vector.c src/vector.h
	gcc -c src/vector.c -o obj/vector.o

clean:
	rm -f obj/*.o bin/*