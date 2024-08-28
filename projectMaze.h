#include <stdio.h>
#include <stdbool.h>
#include "cell.h"
#include "node.h"

struct Node* projectTopRowCell(struct Cell* cell);

struct Node* projectBottomRowCell(struct Cell* cell);

struct Node* projectMaze(struct Cell* head);