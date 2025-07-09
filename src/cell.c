#include "../inc/cell.h"

void die(cell_entity* cell){
  cell->cell_type = DEAD;
}
void revive(cell_entity* cell){
  cell->cell_type = ALIVE;
}