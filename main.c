#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "game.h"
#include "boolean.h"
#include "field.h"

int main(void){
  GROUP *group = (GROUP *)malloc(sizeof(GROUP));
  FIELD *field = (FIELD *)malloc(sizeof(FIELD));
  int debug_loop;
  setup(group,field,FALSE);
  ShuffleOrder(group -> order);
  printf("next order = %d\n", group -> order[0]);
  // for(debug_loop = 0; debug_loop < MAX_MINO;debug_loop++){
  //   PrintMino(group -> block[group -> order[debug_loop]].shape);
  // }
  drop_mino(group, field);
  UpdateCanvas(field);
  PrintField(field);
  return 0;
}
