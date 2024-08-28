#include <stdlib.h>
#include "cell.h"
#include "node.h"

void freeMemoryCell(struct Cell* head) {
    struct Cell* current = head;
    struct Cell* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void freeMemoryNode(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}