#pragma once
#include "../inc/cell.h"

#define height_y 400
#define width_x 700

extern cell_entity main_board[height_y][width_x];
extern cell_entity buffer_board[height_y][width_x];

void init_board();