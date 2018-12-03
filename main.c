#include <stdio.h>
#include <stdlib.h>
#include "block.h"

int main(void){
  GROUP *group = (GROUP *)malloc(sizeof(GROUP));
  int debug_loop;
  SetMino(group);
  for(debug_loop = 0; debug_loop < MAX_MINO;debug_loop++){
    PrintMino(group -> block[debug_loop].shape);
  }
  return 0;
}
