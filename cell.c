#include <stdio.h>
#include <stdbool.h>
#include "cell.h"

bool isTop(struct Cell* cell) {
    return cell->walls & WALL_TOP;
}

bool isBottom(struct Cell* cell) {
    return cell->walls & WALL_BOTTOM;
}

bool isLeft(struct Cell* cell) {
    return cell->walls & WALL_LEFT;
}

bool isRight(struct Cell* cell) {
    return cell->walls & WALL_RIGHT;
}

struct Cell* appendByCell(struct Cell* head, struct Cell* current) {
    if (head == NULL) {
        return current;
    }

    struct Cell* next = head;

    while (next != NULL) {
        if (next->next == NULL) {
            next->next = current;
            break;
        }
        next = next->next;
    }

    return head;
}
