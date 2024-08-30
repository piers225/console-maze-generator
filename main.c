#include <stdio.h>
#include <locale.h>
#include "cell.h"
#include "projectMaze.h"
#include "createCell.h"
#include "freeMemory.h"
#include "node.h"
#include "generateCells.h"
#include "generateMaze.h"

int main(void) 
{
    const int x = 7;
    const int y = 7;
    struct Cell* head = generateCells(x, y);

    generateMaze(NULL, head, head);

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