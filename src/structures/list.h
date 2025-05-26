#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

Node* createNode(const char* value);

void insertAtEnd(Node** list, const char* value);

#endif
