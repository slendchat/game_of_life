#include "../inc/board.h"
#include "../inc/cell.h"


void init_board() 
{
  for (int i = 0; i < height_y; i++) {
    for (int j = 0; j < width_x; j++) {
      if (i == 0 || i == height_y - 1 || j == 0 || j == width_x - 1){
        board[i][j] = (cell_entity){cell_status::WALL, j, i};
      }
      else {
        board[i][j] = (cell_entity){cell_status::DEAD, j, i};
      }

    }
  }
}
