#include "game.h"

void setup (GROUP *group,FIELD *field,bool debug_flag){
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

