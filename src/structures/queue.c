#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "../utils.h"

Queue* NewQueue() {
  Queue* q = malloc(sizeof(Queue));
  if (!q) {
    return NULL;
  }
  q->head = NULL;
  q->tail = NULL;
  q->count = 0;
  return q;
}

QueueNode* NewNode(Node* value) { 
  QueueNode* n = malloc(sizeof(QueueNode));
  if (!n) {
    return NULL;
  }

  n->value = value;
  n->next = NULL;
  return n;
}

bool IsEmpty(Queue queue) {
  return queue.head == NULL && queue.tail == NULL && queue.count == 0;
}

void Enqueue(Queue* queue, QueueNode* node) {
  // Garantee next will be null.
  node->next = NULL;

  if (IsEmpty(*queue)) {
    queue->head = node;
    queue->tail = node;
    queue->count = 1;

    return;
  }

  QueueNode* tail = queue->tail;
  node->next = tail;

  queue->tail = node;
  queue->count++;
}

QueueNode Dequeue(Queue* queue) {
  if(IsEmpty(*queue)) {
    printf("Called dequeue with queue empty. Will exit!\n");
    exit(1);
  }

  if(queue->head == queue->tail) {
    // Copy and free current node.
    QueueNode nodeCopy = *queue->head;
    free(queue->head);

    // Reset queue
    queue->head = NULL;
    queue->tail = NULL;
    queue->count = 0;

    return nodeCopy;
  }

  // Copy and free current head.
  QueueNode nodeCopy = *queue->head;
  free(queue->head);

  // Updating head pointer
  QueueNode* curr = queue->tail;
  while (curr->next != queue->head) {
    curr = curr->next;
  }
  queue->head = curr;
  curr->next = NULL;
  queue->count--;

  return nodeCopy;
}

