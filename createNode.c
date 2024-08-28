#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct Node* createNode(wchar_t data1, wchar_t data2) {
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data[0] = data1;
    newNode->data[1] = data2;
    newNode->next = NULL;
    return newNode;
}