#ifndef FIELD_H
#define FIELD_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "block.h"

#define FIELD_TOP 1
#define SIDE_BUFFER 1
#define HEIGHT 22
#define WIDTH 10

void UpdateCanvas(FIELD*);
void PrintField (FIELD*);
int  drop_mino(GROUP*,FIELD*);

#endif
