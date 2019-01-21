ALL_H   := $(wildcard *.h)
GAME_H  := block.h field.h boolean.h
BLOCK_H := block.h boolean.h
FIEELD  := field.h block.h boolean.h

tetris: main.o block.o game.o field.o
	gcc -o tetris main.o block.o game.o field.o

main.o: main.c $(ALL_H)
	gcc -c main.c

block.o: block.c $(BLOCK_H)
	gcc -c block.c

game.o: game.c $(GAME_H)
	gcc -c game.c

field.o: field.c $(FIELD_H)
	gcc -c field.c

clean:
	rm -f tetris main.o block.o game.o field.o

