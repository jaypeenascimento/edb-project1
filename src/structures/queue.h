#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct QueueNode {
    char* value;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* head;
    QueueNode* tail;
} Queue;

Queue* NewQueue();
QueueNode* NewNode(const char* value);

void Enqueue(Queue* queue, QueueNode* node);
QueueNode* Dequeue(Queue* queue);

bool IsEmpty(Queue* queue);
#endif
