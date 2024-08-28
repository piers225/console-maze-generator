#include <stddef.h>

#ifndef NODE_H
#define NODE_H

// Box-drawing character definitions
#define TOP_LEFT_CORNER L'┌'       // ┌ (Top-left corner)
#define TOP_RIGHT_CORNER L'┐'      // ┐ (Top-right corner)
#define BOTTOM_LEFT_CORNER L'└'    // └ (Bottom-left corner)
#define BOTTOM_RIGHT_CORNER L'┘'   // ┘ (Bottom-right corner)
#define HORIZONTAL_LINE L'─'       // ─ (Horizontal line)
#define VERTICAL_LINE L'│'         // │ (Vertical line)
#define LEFT_T_JUNCTION L'├'       // ├ (Left T-junction)
#define RIGHT_T_JUNCTION L'┤'      // ┤ (Right T-junction)
#define TOP_T_JUNCTION L'┬'        // ┬ (Top T-junction)
#define BOTTOM_T_JUNCTION L'┴'     // ┴ (Bottom T-junction)
#define CROSS_INTERSECTION L'┼'    // ┼ (Cross or four-way intersection)
#define NEW_LINE L'\n'


typedef struct Node {
    wchar_t data[2]; 
    struct Node* next; 
} Node;

struct Node* appendByChar(struct Node* head, wchar_t newChar1, wchar_t newChar2);

struct Node* appendByNode(struct Node* head, struct Node* current);

#endif