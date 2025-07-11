#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include "../inc/cell.h"
#include "../inc/engine.h"

cell_entity main_board[height_y][width_x] = { 0 };
cell_entity buffer_board[height_y][width_x] = { 0 };
cell_entity* dirty_cells[height_y*width_x] = {0};

#define DISTANCE 10

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
      int is_center = (rand() % (height_y*width_x)) < 2;

      if(is_center){
        cell_entity* cell = &(board[y][x]);
        cell_revive(cell);
        for (int dy = -DISTANCE; dy <= DISTANCE; dy++) {
          for (int dx = -DISTANCE; dx <= DISTANCE; dx++) {
            if(cell->pos_y + dy > 1 &&
               cell->pos_y + dy < height_y -2 &&
               cell->pos_x + dx > 1 &&
               cell->pos_x + dx < width_x -2 &&
               abs(dx) + abs(dy) != 0
            ){
              float h = sqrt(dx*dx + dy*dy);
              float max = sqrt(DISTANCE*DISTANCE + DISTANCE*DISTANCE);
              int percentage = (1 - h / max) * 100;
              if((rand() % 100) < percentage){
                cell_revive(&board[y + dy][x + dx]);
              }
            }
  
          }
        }
      }

    }
  }

}

void fill_neighbors()
{
  for (int y = 1; y < height_y - 1; y++) {
    for (int x = 1; x < width_x - 1; x++) {
      for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (abs(dx)+abs(dy) != 0 && main_board[y + dy][x + dx].cell_type == ALIVE){
              main_board[y][x].neighbors++;
            }
        }
      }
      
    }
  }
}

int fill_dirty_array()
{
  int dirty = 0;
  for (int y = 1; y < height_y - 1; y++) {
    for (int x = 1; x < width_x - 1; x++) {
      if (main_board[y][x].cell_type == ALIVE){
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            main_board[y+dy][x+dx].dirty=1;
            dirty_cells[dirty++] = &main_board[y+dy][x+dx];
          }
        }
      }
      
    }
  }
  return dirty;
}
/*
Проходим массив грязных полей и меняем их статус в зависимости от соседей
устанавливаем статус грязного поля всем полям вокруг которых (на расстоянии 1 клетки) есть живая клетка

*/
void change_cell_state(int size_dirty)
{
  for (int i = 0; i < size_dirty; i++){
    /* code */
  }
  
}

/*
Пробегаем массив грязных клеток, если в радиусе 1 клетки нет ни одной живой (neighbors == 0)
тогда убираем у клетки статус грязной.
потом надо будет заново собрать массив грязных клеток в который просто не попадут клетки из первого массива у которых убран
флаг грязный
также надо проработать логику обнволения счета соседей у клеток, думаю что можно просто смотреть грязные клетки и до изменения массива
и обновлять это значение.
*/
void clear_dirty_cells()
{
  return;
}

int game_step()
{
  init_board();
  fill_board(main_board);
  int size_dirty = fill_dirty_array();
  fill_neighbors();
  change_cell_state(size_dirty);
  return 1;
}