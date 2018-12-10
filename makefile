tetris: main.o block.o
	gcc -o tetris main.o block.o

main.o: main.c
	gcc -c main.c

block.o: block.c
	gcc -c block.c

clean:
	rm -f tetris main.o block.o

