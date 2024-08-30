#include <stdio.h>
#include "cell.h"
#include "node.h"

struct Node* projectTopRowCell(Cell* cell) {
    struct Node* node = NULL;
    if (isLeft(cell) && isTop(cell)) {
        node = appendByChar(node, TOP_LEFT_CORNER, HORIZONTAL_LINE);
    }
    if (isLeft(cell) && !isTop(cell)) {
        node = appendByChar(node, VERTICAL_LINE, ' ');
    }
    if (!isLeft(cell) && isTop(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, HORIZONTAL_LINE);
    }
    if (!isLeft(cell) && !isTop(cell)) {
        node = appendByChar(node, BOTTOM_RIGHT_CORNER, ' ');
    }
    if (isRight(cell) && isTop(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, TOP_RIGHT_CORNER);
    }  
    if (isRight(cell) && !isTop(cell)) {
        node = appendByChar(node, ' ', VERTICAL_LINE);
    }
    if (!isRight(cell) && isTop(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, HORIZONTAL_LINE);
    }
    if (!isRight(cell) && !isTop(cell)) {
        node = appendByChar(node, ' ', BOTTOM_LEFT_CORNER);
    }
    return node;
}

struct Node* projectBottomRowCell(Cell* cell) {
    struct Node* node = NULL;
    if (isLeft(cell) && isBottom(cell)) {
        node = appendByChar(node, BOTTOM_LEFT_CORNER, HORIZONTAL_LINE);
    }
    if (isLeft(cell) && !isBottom(cell)) {
        node = appendByChar(node, VERTICAL_LINE, ' ');
    }
    if (!isLeft(cell) && isBottom(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, HORIZONTAL_LINE);
    }
    if (!isLeft(cell) && !isBottom(cell)) {
        node = appendByChar(node, TOP_RIGHT_CORNER, ' ');
    }
    if (isRight(cell) && isBottom(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, BOTTOM_RIGHT_CORNER);
    }  
    if (isRight(cell) && !isBottom(cell)) {
        node = appendByChar(node, ' ', VERTICAL_LINE);
    }
    if (!isRight(cell) && isBottom(cell)) {
        node = appendByChar(node, HORIZONTAL_LINE, HORIZONTAL_LINE);
    }
    if (!isRight(cell) && !isBottom(cell)) {
        node = appendByChar(node, ' ', TOP_LEFT_CORNER);
    }
    return node;
}

struct Node* projectMaze(struct Cell* head) {
    struct Cell* current = head;
    
    struct Node* topRow = NULL;
    struct Node* bottomRow = NULL;
    struct Node* projectedMaze = NULL;
    while (current != NULL) {
        if (current->x == 0) {
            appendByChar(topRow, ' ', NEW_LINE);
            appendByChar(bottomRow, ' ', NEW_LINE);
            projectedMaze = appendByNode(appendByNode(projectedMaze, topRow), bottomRow);
            topRow = NULL;
            bottomRow = NULL;
        }
        topRow = appendByNode(topRow, projectTopRowCell(current));
        bottomRow = appendByNode(bottomRow, projectBottomRowCell(current));
        current = current->next;
    }
    appendByChar(topRow, ' ' , NEW_LINE);
    appendByChar(bottomRow, ' ', NEW_LINE);
    projectedMaze = appendByNode(appendByNode(projectedMaze, topRow), bottomRow);
    return projectedMaze;
}
