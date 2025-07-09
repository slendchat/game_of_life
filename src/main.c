#include <stdio.h>
#include <unistd.h>

#include "../inc/cell.h"
#include "../inc/board.h"
#include "../inc/render.h"
#include "../inc/rules.h"
#include "../inc/utils.h"


int main()
{
  
  init_board();
  
  cell_revive(board[1][1]);
  cell_revive(board[1][2]);
  cell_revive(board[1][3]);
  cell_revive(board[2][2]);
  cell_revive(board[3][1]);
  cell_revive(board[3][2]);
  cell_revive(board[3][3]);
  
  for (;;){
    int changed_cells = 0;

    for (int y = 1; y < height_y - 2; y++){
      for (int x = 1; x < width_x -2; x++){
        if (change_cell_state(board[y][x],check_cell_neighbors(board[y][x])))
          changed_cells++;
      }
    }
    
    draw_frame(board);
    sleep_ms(500);

    if (changed_cells == 0)
      break;
  }

  return 0;
}