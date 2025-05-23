#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "options.c"

Node* L = NULL;

void start() {
    int option;

    homeScreen();
    scanf("%d", &option);
    waitForEnter();
    homeScreenSelection(option); 
};

Node* createNode(const char* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
        return NULL;

    new_node->value = (char*)malloc(strlen(value) + 1);
    if (!new_node->value) {
        free(new_node);
        return NULL;
    }
    strcpy(new_node->value, value);
    new_node->next = NULL;

    return new_node;
}

void insertAtEnd(Node** list, const char* value) {
    Node* new_node = createNode(value);
    if (!new_node)
        return;

    if (*list == NULL) {
        *list = new_node;
        return;
    }

    Node* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void printList(Node* list) {
    Node* current = list;

    clearScreen();
    printf("===== Lista de pedidos =====\n\n");
    while (current != NULL) {
        printf("- %s\n", current->value);
        current = current->next;
    }
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");

    waitForEnter();
}

void printArray(const char* const array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, array[i]);
    }
}

void homeScreen() {
    clearScreen();
    printf("===== Menu =====\n\n");
    printArray(HOME_MENU, ARRAY_LENGTH(HOME_MENU));
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void platesScreen() {
    clearScreen();
    printf("===== Cardápio =====\n\n");
    printArray(PLATES_MENU, ARRAY_LENGTH(PLATES_MENU));
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void mainPlatesScreen() {
    clearScreen();
    printf("===== Entradas =====\n\n");
    printArray(MAIN_PLATES, ARRAY_LENGTH(MAIN_PLATES));
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void appetizersScreen() {
    clearScreen();
    printf("===== Pratos Principais =====\n\n");
    printArray(APPETIZERS, ARRAY_LENGTH(APPETIZERS));
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void dessertsScreen() {
    clearScreen();
    printf("===== Sobremesas =====\n\n");
    printArray(DESSERTS, ARRAY_LENGTH(DESSERTS));
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void invalidOptionScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Opção inválida!\n");
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");

    waitForEnter();
}

void successfulAddScreen() { 
    clearScreen();
    printf("===== \n\n");
    printf("Adicionado com sucesso!\n");
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");

    waitForEnter();
}
void unsuccessfulAddScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Erro ao adicionar\n\n");
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");

    waitForEnter();
};

void notImplementedYetScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Não implementado ainda\n");
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...\n");

    waitForEnter();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void homeScreenSelection(int option) {
    switch (option) {
        case 1:
            platesScreen();               
            scanf("%d", &option);         
            waitForEnter();               
            platesScreenSelection(option);
            break;
        case 2:
            // TODO: Método para remover pedido
            notImplementedYetScreen();
            // scanf("%d", &option);
            break;
        case 3:
            // TODO: Método para processar pedido
            notImplementedYetScreen();
            // scanf("%d", &option);
            break;
        case 4:
            printList(L);
            break;
        case 5:
            // TODO: Método para listar pedidos da cozinha
            notImplementedYetScreen();
            // scanf("%d", &option);
            break;
        default:
            invalidOptionScreen();
            break;
    }
}

void platesScreenSelection(int option) { 
    switch (option) {
        case 1:
            appetizersScreen();
            scanf("%d", &option); 
            waitForEnter(); 
            appetizersScreenSelection(option);
            break;
        case 2:
            mainPlatesScreen();
            scanf("%d", &option);
            waitForEnter();
            mainPlatesScreenSelection(option);
            break;
        case 3:
            dessertsScreen();
            scanf("%d", &option);
            waitForEnter();
            dessertsScreenSelection(option);
            break;
        default:
            invalidOptionScreen();
            break;
    }
}

void appetizersScreenSelection(int option) { 
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(APPETIZERS));
    if (!isValid) {
      invalidOptionScreen();
      return;
    }

    insertAtEnd(&L, APPETIZERS[option - 1]);
    successfulAddScreen();
}

void mainPlatesScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(MAIN_PLATES));
    if (!isValid) {
      invalidOptionScreen();
      return;
    }

    insertAtEnd(&L, MAIN_PLATES[option - 1]);
    successfulAddScreen();
}

void dessertsScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(DESSERTS));
    if (!isValid) {
      invalidOptionScreen();
      return;
    }

    insertAtEnd(&L, DESSERTS[option - 1]);
    successfulAddScreen();
}

bool checkIsAValidOption(int option, int amount) {
    return isAValidOption(option, amount);
}

int isAValidOption(int option, int range) {
    return inRange(option, 1, range);
}

int inRange(int val, int min, int max) {
    return val >= min && val <= max;
}

void waitForEnter() {
    getchar();
}
