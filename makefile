tetris: main.o block.o game.o field.o
	gcc -o tetris main.o block.o game.o field.o

main.o: main.c
	gcc -c main.c

block.o: block.c
	gcc -c block.c

game.o: game.c
	gcc -c game.c

field.o: field.c
	gcc -c field.c

main.c: block.h game.h field.h
block.c: block.h
game.c: game.h
field.c: field.h

clean:
	rm -f tetris main.o block.o game.o field.o

