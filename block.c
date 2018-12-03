#include "block.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int I_MINO[4][4] = \
  {{0,0,0,0},                                   \
   {0,0,0,0},                                   \
   {1,1,1,1},                                   \
   {0,0,0,0}};
const int J_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {1,0,0,0},\
   {1,1,1,0}};
const int L_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {0,0,1,0},\
   {1,1,1,0}};
const int S_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {0,1,1,0},\
   {1,1,0,0}};
const int Z_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {1,1,0,0},\
   {0,1,1,0}};
const int T_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {0,1,0,0},\
   {1,1,1,0}};
const int O_MINO[4][4] = \
  {{0,0,0,0},\
   {0,0,0,0},\
   {0,1,1,0},\
   {0,1,1,0}};


void SetMino(GROUP *group){
  memcpy(group -> block[0].shape , I_MINO, sizeof(group -> block[0].shape));
  memcpy(group -> block[1].shape , J_MINO, sizeof(group -> block[1].shape));
  memcpy(group -> block[2].shape , L_MINO, sizeof(group -> block[2].shape));
  memcpy(group -> block[3].shape , S_MINO, sizeof(group -> block[3].shape));
  memcpy(group -> block[4].shape , Z_MINO, sizeof(group -> block[4].shape));
  memcpy(group -> block[5].shape , T_MINO, sizeof(group -> block[5].shape));
  memcpy(group -> block[6].shape , O_MINO, sizeof(group -> block[6].shape));
}

void PrintMino(int mino[4][4]){
  int i,j;
  for(i = 0;i < 4;i++){
    for(j = 0;j < 4;j++){
      if(mino[i][j] == 0) printf(" ");
      else printf("&");
    }
    printf("\n");
  }
}
  
