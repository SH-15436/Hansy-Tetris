#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string.h>
#include "block.h"
#include "field.h"
#include "boolean.h"

void setup (GROUP*,FIELD*,BOOL);

void Manipulate_mino(void);
void to_ground_mino(void);
void check_line_clear(void);
#endif
