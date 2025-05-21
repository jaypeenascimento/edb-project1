#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"

Queue* NewQueue() {
  Queue* q = malloc(sizeof(Queue));
  if (!q) {
    return NULL;
  }
  q->head = NULL;
  q->tail = NULL;
  return q;
}

QueueNode* NewNode(const char* value) { 
  QueueNode* n = malloc(sizeof(QueueNode));
  if (!n) {
    return NULL;
  }

  n->value = (char*)malloc(strlen(value) + 1);
  if (!n->value) {
      free(n);
      return NULL;
  }

  n->next = NULL;

  strcpy(n->value, value);
  return n;
}

bool IsEmpty(Queue queue) {
  return queue.head == NULL && queue.tail == NULL;
}
