#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "../inc/cell.h"
#include "../inc/engine.h"

cell_entity main_board[height_y][width_x] = { 0 };
cell_entity buffer_board[height_y][width_x] = { 0 };
cell_entity* dirty[height_y*width_x];

#define BLUR 10

void init_board() 
{
  for (int i = 0; i < height_y; i++) {
    for (int j = 0; j < width_x; j++) {
      if (i == 0 || i == height_y - 1 || j == 0 || j == width_x - 1){
        main_board[i][j] = (cell_entity){WALL, j, i, 0, 0};
        buffer_board[i][j] = (cell_entity){WALL, j, i, 0, 0};
      }
      else {
        main_board[i][j] = (cell_entity){DEAD, j, i, 0, 0};
        buffer_board[i][j] = (cell_entity){DEAD, j, i, 0, 0};
      }

    }
  }
}

void fill_board(cell_entity board[height_y][width_x])
{
    // Generate some alive cells on the board
  srand(time(NULL));
  for (int y = 1; y < height_y - 1; y++) {
    for (int x = 1; x < width_x - 1; x++) {

      int is_center = (rand() % 100) < 2;
      if(is_center){
        cell_entity* cell = &(board[y][x]);
        cell_revive(cell);
        for (int dy = -BLUR; dy <= BLUR; dy++) {
          for (int dx = -BLUR; dx <= BLUR; dx++) {
            if(cell->pos_y + dy > 1 &&
               cell->pos_y + dy < height_y -2 &&
               cell->pos_x + dx > 1 &&
               cell->pos_x + dx < width_x -2 &&
               dx + dy != 0
            ){
              abs()
            }
  
          }
        }
      }


    }
  }
}

void fill_dirty_array(int dirty_cells)
{
  for (int y = 1; y < height_y - 1; y++) {
    for (int x = 1; x < width_x - 1; x++) {
      if (main_board[y][x].dirty == 1)
      {
        /* code */
      }
      
      dirty[dirty_cells++] = &main_board[y][x];
    }
  }
  
}

void game_step()
{
  int dirty_cells = 0;


}