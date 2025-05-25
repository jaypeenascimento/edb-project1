#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
// Definição das estruturas

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

// Método de inicialização

void start();

// Métodos da lista

Node* createNode(const char* value);

void insertAtEnd(Node** list, const char* value);

struct Node* removeOrder(struct Node* head, int position);

void printOrdersForRemove(Node* list);

void printOrders(Node* list);

void printList(Node* current);

// void freeList(Node* first);

// Métodos da Fila

void PrintOrderQueue();

void doPrintOrderQueue();

// Métodos de Exibição de tela

void customScreen(char* title, char* items[], int size);

void customMessageScreen(char* message);

void printArray(char* array[], int size);

void clearScreen();

// Métodos de Seleção de tela

void homeScreenSelection(int option);

void platesScreenSelection(int option);

void mainPlatesScreenSelection(int option);

void appetizersScreenSelection(int option);

void dessertsScreenSelection(int option);

// Outros

bool checkIsAValidOption(int option, int amount);

int isAValidOption(int option, int range);

int inRange(int val, int min, int max);

void waitForEnter();

void flushInput();

#endif
