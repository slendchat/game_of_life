#pragma once

#include "../inc/cell.h"

#define height_y 50
#define width_x 100

extern cell_entity main_board[height_y][width_x];
extern cell_entity buffer_board[height_y][width_x];
extern cell_entity old_board[height_y][width_x];

void init_board();

int get_cells_info(cell_entity board[height_y][width_x]);
void change_cell_state(cell_entity board[height_y][width_x], cell_entity buffer[height_y][width_x],cell_entity* changing_cells_list, int changing_cells);
int game_step();