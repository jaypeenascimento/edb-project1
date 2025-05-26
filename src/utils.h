#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "structures/list.h"
// Definição das estruturas

// Método de inicialização

void start();

// Métodos da lista

struct Node* removeOrder(struct Node* head, int position);

// Métodos da Fila

void ProcessOrder();

void doProcessOrder();

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
