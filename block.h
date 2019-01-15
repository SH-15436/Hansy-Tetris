#ifndef BLOCK_H
#define BLOCK_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "boolean.h"

#define MAX_MINO 7
#define SHUFFLE_NUM 1000

#define HEIGHT 22
#define WIDTH 10

typedef struct MINO{
  char type;
  int shape[4][4];
  int drop_counter;
} MINO;

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

typedef struct GROUP{
  MINO block[7];
  int order[7];
  int order_selecter;
} GROUP;

void SetMino (GROUP*);
void ShuffleOrder (int [7]);

void PrintMino(int [4][4]);

extern const int I_MINO[4][4];
extern const int J_MINO[4][4];
extern const int L_MINO[4][4];
extern const int S_MINO[4][4];
extern const int Z_MINO[4][4];
extern const int T_MINO[4][4];
extern const int O_MINO[4][4];

#endif
