#include "game.h"

void setup (GROUP *group,FIELD *field,BOOL debug_flag){
  int i,j;
  SetMino(group);
  group -> order_selecter = 0;
  // 定数で初期化するもの
  for(i = 0;i < MAX_MINO;i++){
    group -> order[i] = i;
    group -> block[i].drop_counter = 0;
  }
  // 画面の初期化
  for(i = 0;i < HEIGHT + 1;i++){
    if(debug_flag) printf("i = %d\n",i);
    if(i != HEIGHT){
      for(j = 0;j < WIDTH + 3;j++){
        switch(j){
        case 0      :
        case WIDTH+1:
          field -> disp_field[i][j] = '|';
          break;
        case WIDTH+2:
          field -> disp_field[i][j] = '\n';
          break;
        default     :
          field -> disp_field[i][j] = ' ';
          break;
        }
      }
    }else{
      field -> disp_field[i][0] = field -> disp_field[i][WIDTH+1] = '+';
      field -> disp_field[i][WIDTH+2] = '\n';
      for(j = 1;j <= WIDTH;j++){
        field -> disp_field[i][j] = '-';
      }
    }
  }
  if(debug_flag){
    for(i = 0;i < HEIGHT + 1;i++){
      printf("%2d ",i);
      for(j = 0;j < WIDTH + 3;j++)
        printf("%3d ",field -> disp_field[i][j]);
      printf("\n");
    }
  }
  // ランダムシードの作成
  srand((unsigned)time(NULL));
}

/* ゲームのメインループ
 * ここを1ループすると、1ミノのアクションが終了する */
int game_loop(GROUP *group, FIELD *field){
  if(drop_mino(group, field)) return 0;
  // Manipulate_mino();
  // to_ground_mino();
  // check_line_clear();
  return 1;
}

void Manipulate_mino(GROUP* group, FIELD* field){

}

BOOL is_ground_mino(GROUP* group,FIELD* field){
  return FALSE;
}

void check_line_clear(FIELD *field){
  int line;
  const int CLEAR_LINE[] = {1,1,1,1,1,1,1,1,1,1};
  int delete_line_map[WIDTH] = {0};
  for(line = 0;line < HEIGHT;line++)
    if(memcmp(field -> bit_field[line],CLEAR_LINE,sizeof(CLEAR_LINE) == 0)) delete_line_map[line] = 1;
  delete_line(field, delete_line_map);
}

void drop_mino_oneline(GROUP *group,FIELD *field){
  int i;
  int order = group -> order[group -> order_selecter];
  int drop_counter = group -> block[order].drop_counter++;
  const BOOL debug_FLAG = FALSE;
  if(debug_FLAG){
    printf("-----drop_mino_oneline----------\n");

    puts("line-debug");
    for(i = 0; i < 10;i++){
      printf("%d",field -> bit_field[drop_counter + FIELD_TOP][i]);
    }puts("");
    for(i = 0; i < 10;i++){
      printf("%d",field -> bit_field[drop_counter +1+ FIELD_TOP][i]);
    }puts("");
    puts("shape-debug");
    for(i = 0;i < 4;i++){
      printf("%d",group -> block[order].shape[2][i]);
    }puts("");
    for(i = 0;i < 4;i++){
      printf("%d",group -> block[order].shape[3][i]);
    }puts("");

    printf("drop_counter = %d\n",drop_counter);
    printf("order = %d\n",order);
    printf("NEXT_MINO = %d\n",order);
  }

  if(is_ground_mino(group,field) == FALSE){

    for(i = 0; i < BLOCK_WIDTH;i++){
      field -> bit_field[drop_counter+FIELD_TOP][i + R_SPACE] \
      ^= group -> block[order].shape[2][i];
      field -> bit_field[drop_counter+1+FIELD_TOP][i + R_SPACE] \
      ^= group -> block[order].shape[3][i];
    }

    if(debug_FLAG){
      for(i = 0; i < 10;i++){
        printf("%d",field -> bit_field[drop_counter + FIELD_TOP][i]);
      }puts("");
      for(i = 0; i < 10;i++){
        printf("%d",field -> bit_field[drop_counter+1+FIELD_TOP][i]);
      }puts("");

      UpdateCanvas(field);
      PrintField(field);
      printf("-----drop_mino_oneline_end-----\n");
    }
    drop_mino(group,field);
  }
}
