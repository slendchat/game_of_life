#pragma once

typedef enum _cell_status{
    DEAD = 0,
    ALIVE,
    WALL
}cell_status;

typedef struct {
    cell_status cell_type;
    int pos_x;
    int pos_y;
    char neighbors;
    char dirty;
} cell_entity;

void cell_die(cell_entity* cell);
cell_entity* cell_revive(cell_entity* cell);