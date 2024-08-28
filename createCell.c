#include <stdlib.h>
#include <stdio.h>
#include "cell.h"

struct Cell* createCell(int x, int y, int walls) {
    struct Cell* newCell = (struct Cell *)malloc(sizeof(struct Cell));
    if (!newCell) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newCell->x = x;
    newCell->y = y;
    newCell->walls = walls;
    newCell->next = NULL; 
    return newCell;
}