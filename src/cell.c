#include "../inc/cell.h"

void cell_die(cell_entity* cell){
  cell->cell_type = DEAD;
}
cell_entity* cell_revive(cell_entity* cell){
  cell->cell_type = ALIVE;
  cell->dirty=1;
  return cell;
}