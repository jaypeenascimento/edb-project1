#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Node* createNode(const char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
        return NULL;

    new_node->value = (char*)malloc(strlen(value) + 1);
    if (!new_node->value) {
        free(new_node);
        return NULL;
    }
    strcpy(new_node->value, value);
    new_node->next = NULL;

    return new_node;
}

void insertAtEnd(Node** list, const char* value) {
    Node* new_node = createNode(value);
    if (!new_node)
        return;

    if (*list == NULL) {
        *list = new_node;
        return;
    }

    Node* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

