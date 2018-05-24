all: bin/chess bin/test

bin/chess: build/main.o build/board.o build/board_print_plain.o
	gcc -Wall -std=c99 -Werror build/main.o build/board.o build/board_print_plain.o -o bin/chess

build/main.o: src/main.c
	gcc -Wall-std=c99 -Werror -c src/main.c -o build/main.o

build/board.o: src/board.c
	gcc -Wall -std=c99 -Werror  -c src/board.c -o build/board.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -std=c99 -Werror  -c src/board_print_plain.c -o build/board_print_plain.o

bin/test: build/test/board_test.o build/board.o build/board_print_plain.o build/test/main.o
	gcc -Wall -std=c99 build/test/board_test.o build/board.o build/board_print_plain.o build/test/main.o -o bin/test

build/test/board_test.o: test/board_test.c
	gcc -Wall -std=c99 -c test/board_test.c -o build/test/board_test.o -Ithirdparty -Isrc

build/test/main.o: test/main.c
	gcc -Wall -std=c99 -c test/main.c -o build/test/main.o -Ithirdparty

test: bin/test
	bin/test		 

.PHONY: clean
clean:
	rm -rf build/*.o

