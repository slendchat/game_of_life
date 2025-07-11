#pragma once

#include "../inc/cell.h"

#define height_y 50
#define width_x 100

extern cell_entity main_board[height_y][width_x];
extern cell_entity buffer_board[height_y][width_x];
extern cell_entity* dirty[height_y*width_x];

void init_board();

void fill_board(cell_entity board[height_y][width_x]);