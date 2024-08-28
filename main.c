#include <stdio.h>
#include <locale.h>
#include "cell.h"
#include "projectMaze.h"
#include "createCell.h"
#include "freeMemory.h"
#include "node.h"
#include "generateCells.h"

int main(void) 
{
    struct Cell* head = generateCells(6, 6);

    // struct Cell* head = createCell(0, 0, WALL_TOP | WALL_LEFT); // Top-left corner cell with top and left walls
    // head->next = createCell(1, 0, WALL_TOP | WALL_RIGHT); // Top-right corner cell with top and right walls

    // head->next->next = createCell(0, 1, WALL_BOTTOM | WALL_LEFT); // Bottom-left corner cell with bottom and left walls
    // head->next->next->next = createCell(1, 1, WALL_BOTTOM | WALL_RIGHT); // Bottom-right corner cell with bottom and right walls

    struct Node* current = projectMaze(head);

    printf("\n");
    setlocale(LC_ALL, "C.UTF-8");
    while (current != NULL) {
        printf("%lc%lc", current->data[0], current->data[1]);
        current = current->next;
    }
    printf("\n");

    freeMemoryCell(head);
    freeMemoryNode(current);

    return 0;
}