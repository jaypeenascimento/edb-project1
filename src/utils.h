#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "structures/list.h"

// Método de inicialização

void start();

// Métodos da lista

struct Node* removeOrder(struct Node* head, int position);

// Métodos da Fila

void ProcessOrder();

void doProcessOrder();

// Outros

void waitForEnter();

void flushInput();

#endif
