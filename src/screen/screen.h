#ifndef SCREEN_H
#define SCREEN_H

#include "../structures/list.h"
#include "../structures/queue.h"

void clearScreen();
void printArray(char* array[], int size);
void customScreen(char* title, char* items[], int size);
void customMessageScreen(char* message);
void printOrdersForRemove(Node* list);
void printOrders(Node* list);
void printList(Node* current);
void PrintOrderQueue(Queue* queue);
void doPrintOrderQueue(Queue* queue);

#endif
