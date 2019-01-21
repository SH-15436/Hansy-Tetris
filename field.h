#ifndef FIELD_H
#define FIELD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "block.h"

#define FIELD_TOP 1
#define SIDE_BUFFER 1
#define HEIGHT 22
#define WIDTH 10

/*
  bit_field  : ブロックの有無のboolean
  disp_field : 画面に描画されるフィールド
  hold       : ホールドしたミノのtype
*/
typedef struct FIELD{
  char disp_field[HEIGHT + 1][WIDTH + 3];
  int bit_field[HEIGHT][WIDTH]; // field[縦幅][横幅]
  char hold;
} FIELD;

void UpdateCanvas(FIELD*);
void PrintField (FIELD*);
int  drop_mino(GROUP*,FIELD*);
void delete_line(FIELD*,int[]);

#endif
