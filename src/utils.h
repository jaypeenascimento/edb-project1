#ifndef UTILS_H
#define UTILS_H

// Definição das estruturas

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct OrderQueue {
    Node* head;
    Node* tail;
} OrderQueue;

// Método de inicialização

void start();

// Métodos da lista

Node* createNode(const char* value);

void insertAtEnd(Node** list, const char* value);

void printList(Node* list);

// void freeList(Node* first);

// Métodos de Exibição de tela

void homeScreen();

void platesScreen();

void mainPlatesScreen();

void appetizersScreen();

void dessertsScreen();

void invalidOptionScreen();

void successfulAddScreen();

void unsuccessfulAddScreen();

void clearScreen();

void notImplementedYetScreen();

// Métodos de Seleção de tela

void homeScreenSelection(int option);

void platesScreenSelection(int option);

void mainPlatesScreenSelection(int option);

void appetizersScreenSelection(int option);

void dessertsScreenSelection(int option);

// Outros

void checkIsAValidOption(int option, int amount);

int isAValidOption(int option, int range);

int inRange(int val, int min, int max);

#endif