#include <stdlib.h>
#include <time.h>
#include "cell.h"
#include "freeMemory.h"

Cell* findCell(int x, int y, Cell* head) {
    struct Cell* current = head;
    while (current != NULL) {
        if (current->x == x && current->y == y) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


Cell** shuffle(Cell* current, Cell* head) {
    Cell* neighbors[4];

    Cell* top = findCell(current->x, current->y + 1, head);
    Cell* bottom = findCell(current->x, current->y - 1, head);
    Cell* right = findCell(current->x + 1, current->y, head);
    Cell* left = findCell(current->x - 1, current->y, head);

    neighbors[0] = top;
    neighbors[1] = left;
    neighbors[2] = right;
    neighbors[3] = bottom;
    for (int i = 3; i > 0; --i) {
        int j = rand() / (RAND_MAX / (i + 1));
        Cell* temp = neighbors[i];
        neighbors[i] = neighbors[j];
        neighbors[j] = temp;
    }

    Cell** shuffled_neighbors = (Cell**)malloc(4 * sizeof(Cell*));
    for (int i = 0; i < 4; i++) {
        shuffled_neighbors[i] = neighbors[i];
    }

    return shuffled_neighbors;
}

void carveEdge(Cell* last, Cell* next) {
    if (last == NULL) {
        return;
    }
    if (last->x == next->x && last->y == next->y - 1) {
        last->walls &= ~WALL_BOTTOM; 
        next->walls &= ~WALL_TOP; 
    } else if (last->x == next->x && last->y == next->y + 1) {
        last->walls &= ~WALL_TOP;
        next->walls &= ~WALL_BOTTOM;
    } else if (last->x == next->x - 1 && last->y == next->y) {
        last->walls &= ~WALL_RIGHT;
        next->walls &= ~WALL_LEFT;
    } else if (last->x == next->x + 1 && last->y == next->y) {
        last->walls &= ~WALL_LEFT;
        next->walls &= ~WALL_RIGHT;
    }
}

void generateMaze(Cell* last, Cell* next, Cell* head) {
    if (last == NULL) {
        srand(time(NULL));
    }
    if (next->visited == true) {
        return;
    }

    next->visited = true;

    carveEdge(last, next);

    Cell** shuffledNeighbors = shuffle(next, head);

    for (int i = 0; i < 4; i++) {
        if (shuffledNeighbors[i] == NULL) {
            continue;
        }
        generateMaze(next, shuffledNeighbors[i], head);
    }

    free(shuffledNeighbors);
}