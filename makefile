CC=gcc
RM=rm -rf
OUT=vector

all: build

build: src/string_reader.o src/vector.o
	$(CC) -o $(OUT) src/string_reader.c src/vector.c
	$(RM) *.o

string_reader.o: src/string_reader.c src/vector.h
	$(CC) -c src/string_reader.c

vector.o: src/vector.c src/vector.h
	$(CC) -c src/vector.c
tests:
	make build
	cat test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt test/lorem1.txt > test/lorem2.txt
	cat test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt test/lorem2.txt > test/lorem3.txt
	cat test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt test/lorem3.txt > test/lorem4.txt
	cat test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt test/lorem4.txt > test/lorem5.txt
	cat test/lorem5.txt test/lorem5.txt test/lorem5.txt test/lorem5.txt > test/loremextreme.txt 
	./vector test/lorem2.txt
	./vector test/lorem3.txt
	./vector test/lorem4.txt
	./vector test/lorem5.txt
	./vector test/loremextreme.txt	

clean:
	$(RM) src/*.o $(OUT)
