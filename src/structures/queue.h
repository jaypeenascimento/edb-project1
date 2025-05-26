#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "../utils.h"

typedef struct QueueNode {
    Node* value;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* head;
    QueueNode* tail;
    int count;
} Queue;

Queue* NewQueue();
QueueNode* NewNode(Node* value);

void Enqueue(Queue* queue, QueueNode* node);
QueueNode Dequeue(Queue* queue);

bool IsEmpty(Queue queue);
#endif
