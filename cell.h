#include <stdbool.h>

#ifndef CELL_H
#define CELL_H

#define WALL_TOP 0x1
#define WALL_RIGHT 0x2
#define WALL_BOTTOM 0x4
#define WALL_LEFT 0x8

typedef struct Cell {
    int x, y;               // Coordinates of the cell in the maze
    int walls;              // Bit field to represent walls (top, right, bottom, left)
    struct Cell* next;      // Pointer to the next cell (optional for other data structure needs)
    bool visited;
} Cell;

bool isTop(struct Cell* cell);
bool isBottom(struct Cell* cell);
bool isLeft(struct Cell* cell);
bool isRight(struct Cell* cell);
Cell* appendByCell(struct Cell* head, struct Cell* current);

#endif