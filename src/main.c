#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include "../inc/cell.h"
#include "../inc/engine.h"
#include "../inc/render.h"
#include "../inc/utils.h"


int main(int argc, char* argv[])
{
  // init plain board
  init_board();




  // MAIN LOOP
  for (;;){

    draw_frame(main_board);
    
    if(!game_step())
      break;

    // sleep_ms(100);

  }

  return 0;
}
