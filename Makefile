CC = gcc
FLAG = -Wall -Werror

all:bin/chsv

test:bin/chsv_test


bin/chsv_test: build/test/main.o build/board.o
	$(CC) $(FLAG) build/test/main.o build/board.o -o bin/chsv_test



build/test/main.o:test/main.c
	$(CC) $(FLAG) -I src -I thirdparty -c test/main.c -o build/test/main.o



bin/chsv: build/main.o build/board.o
	$(CC) $(FLAG) -o bin/chsv build/main.o build/board.o
	
build/main.o:src/main.c
	$(CC) $(FLAG) -c -o build/main.o src/main.c
	
build/board.o:src/board.c
	$(CC) $(FLAG) -c -o build/board.o src/board.c
	
dir:
	mkdir build
	mkdir bin
	
.PHONY: clean
clean:
rm -rf build/*.o
