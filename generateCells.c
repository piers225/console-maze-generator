#include "cell.h"
#include "createCell.h"

struct Cell* generateCells(int width, int height) {
    struct Cell* head = NULL; 
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            head = appendByCell(head, createCell(x, y, WALL_TOP));
        }
    }
    return head;
}