#include <stdlib.h>
#include "node.h"
#include "createNode.h"

struct Node* appendByChar(struct Node* head, wchar_t newChar1, wchar_t newChar2) {
    return appendByNode(head, createNode(newChar1, newChar2));
}

struct Node* appendByNode(struct Node* head, struct Node* current) {
    if (head == NULL) {
        return current;
    }

    struct Node* next = head;

    while (next != NULL) {
        if (next->next == NULL) {
            next->next = current;
            break;
        }
        next = next->next;
    }

    return head;
}
