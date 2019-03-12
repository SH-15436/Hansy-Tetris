#include <stdio.h>
#include <stdlib.h>
#include "block.h"
#include "game.h"
#include "boolean.h"
#include "field.h"

int main(void){
  GROUP *group = (GROUP *)malloc(sizeof(GROUP));
  FIELD *field = (FIELD *)malloc(sizeof(FIELD));
  int debug_loop,i = 0;
  setup(group,field,FALSE);
  ShuffleOrder(group -> order);
  printf("setup()\n");
  printf("%d,%d,%d,%d,%d,%d,%d\n",group -> order[0],group -> order[1],group -> order[2],group -> order[3],group -> order[4],group -> order[5],group -> order[6]);
  UpdateCanvas(field);
  PrintField(field);
  printf("next order = %d\n", group -> order[0]);
  puts("");
  // for(debug_loop = 0; debug_loop < MAX_MINO;debug_loop++){
  //   PrintMino(group -> block[group -> order[debug_loop]].shape);
  // }
  drop_mino(group, field);
  UpdateCanvas(field);
  PrintField(field);
  for(debug_loop = 0; debug_loop < 25; debug_loop++){
    drop_mino_oneline(group, field);
    UpdateCanvas(field);
    PrintField(field);
    int i;
    for(i = 0; i < 12;i++)puts("");
  }
  UpdateCanvas(field);
  PrintField(field);
  return 0;
}
