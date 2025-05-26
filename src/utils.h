#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
// Definição das estruturas

// Método de inicialização

void start();

// Métodos da lista

void printOrdersForRemove(Node* list);

void printOrders(Node* list);

void printList(Node* current);

// void freeList(Node* first);

// Métodos da Fila

void ProcessOrder();

void doProcessOrder();

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
