#include "../inc/rules.h"
#include "../inc/board.h"
#include "../inc/cell.h"

int check_cell_neighbors(cell_entity *cell)
{
  int alive_neghbors = 0;
  int x = cell->pos_x;
  int y = cell->pos_y;

  // Check all 8 neighbors
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j <= 1; j++){

      if (i == 0 && j == 0)
        continue;

      if ( board[y + i][x + j].cell_type == ALIVE){
        alive_neghbors++;
      }

    }
  }  

  return alive_neghbors;
}

bool change_cell_state(cell_entity *cell, int alive_neghbors)
{
  if ((alive_neghbors < 2 || alive_neghbors > 3) && cell->cell_type != cell_type::DEAD) {
    cell->die();
    return true;
  } else if ((alive_neghbors == 3) && cell->cell_type != cell_type::ALIVE) {
    cell->revive();
    return true;
  }
  //return false if no change is made
  return false;
}

