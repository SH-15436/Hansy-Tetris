#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string.h>
#include "block.h"
#include "field.h"
#include "boolean.h"

#define R_SPACE 3

void setup (GROUP*,FIELD*,BOOL);

void Manipulate_mino(GROUP*, FIELD*);
BOOL is_ground_mino(GROUP*, FIELD*, int);
void check_line_clear(FIELD*);
void drop_mino_oneline(GROUP*,FIELD*);
#endif
