#ifndef BLOCK_H
#define BLOCK_H

#define MAX_MINO 7

typedef struct MINO{
  char type;
  int shape[4][4];
} MINO;

typedef struct GROUP{
  MINO block[7];
} GROUP;

void SetMino (GROUP*);

void PrintMino(int [4][4]);

extern const int I_MINO[4][4];
extern const int J_MINO[4][4];
extern const int L_MINO[4][4];
extern const int S_MINO[4][4];
extern const int Z_MINO[4][4];
extern const int T_MINO[4][4];
extern const int O_MINO[4][4];

#endif
