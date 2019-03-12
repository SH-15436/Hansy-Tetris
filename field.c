#include "field.h"

void UpdateCanvas(FIELD *field){
  int x,y,bit_cache;
  char char_cache;
  for(y = 0;y < HEIGHT;y++){
    for(x = 0;x < WIDTH;x++){
      bit_cache = field -> bit_field[y][x];
      char_cache = field -> disp_field[y][x + 1];
      if(bit_cache == 0 && char_cache != ' ')
        field -> disp_field[y][x + 1] = ' ';
      else if(bit_cache == 1 && char_cache != '#')
        field -> disp_field[y][x + 1] = '#';
    }
  }
}

void PrintField (FIELD *field){
  int i,j;
  for(i = 0;i < HEIGHT + 1;i++){
    printf("%2d ",i);
    for(j = 0;j < WIDTH + 3;j++)
      printf("%c",field -> disp_field[i][j]);
  }
}

int drop_mino(GROUP *group, FIELD *field){
  int loop, buf_field;
  int order_selecter = group -> order_selecter;
  int order = group -> order[order_selecter];
  int drop_mino_counter = group -> block[order].drop_counter;
  const BOOL debug_FLAG = FALSE;
  if (debug_FLAG){
    printf("DROP_MINO()\n");
    printf("drop_counter %d\n",group -> block[order].drop_counter);
    printf("order = %d\n",order);
  }
  for(loop = 0, buf_field = 0;loop < 4;loop++){
    buf_field <<= 1;
    buf_field += field -> bit_field[drop_mino_counter + FIELD_TOP + 1][4 + loop] & group -> block[order].shape[3][loop];
  }
  if(debug_FLAG) printf("buf_field = %d\n",buf_field);
  if(buf_field != 0) return 1;
  memcpy(&(field -> bit_field[drop_mino_counter + FIELD_TOP][3]),&(group -> block[order].shape[2][0]),sizeof(int)*4);
  memcpy(&(field -> bit_field[drop_mino_counter + FIELD_TOP + 1][3]),&(group -> block[order].shape[3][0]), sizeof(int)*4);

  if(debug_FLAG){
    for(loop = 0;loop < 4;loop++) printf("%d",group -> block[order].shape[2][loop]);
    printf("\n");
    for(loop = 0;loop < 4;loop++) printf("%d",group -> block[order].shape[3][loop]);
    printf("\n");
    for(loop = 0;loop < 10;loop++){
      printf("%d",field -> bit_field[drop_mino_counter + FIELD_TOP][loop]);
    }
    printf("\n");
    for(loop = 0;loop < 10;loop++){
      printf("%d",field -> bit_field[drop_mino_counter + FIELD_TOP + 1][loop]);
    }
    printf("\n");
  }
  return 0;
}


void delete_line(FIELD* field,int delete_line_map[]){
  int i,cache;
  for(i = WIDTH-1,cache = 0;i >= 0;i--){
    if(delete_line_map[i] == 0){
      cache++;
      memcpy(field -> bit_field[i],field -> bit_field[WIDTH - cache],sizeof(field -> bit_field));
    }
  }
}
