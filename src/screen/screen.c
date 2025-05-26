#include <stdio.h>
#include <stdlib.h>
#include "../structures/list.h"
#include "../structures/queue.h"
#include "screen.h"
#include "../utils.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printArray(char* array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, array[i]);
    }
}

void customScreen(char* title, char* items[], int size) {
    clearScreen();
    printf("===== %s =====\n\n", title);
    printArray(items, size);
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void customMessageScreen(char* message) {
    clearScreen();
    printf("===== \n\n");
    printf("%s\n", message);
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");
    waitForEnter();
}

void printOrdersForRemove(Node* list) {
    Node* current = list;

    clearScreen();
    printf("===== Lista de pedidos =====\n\n");
    printList(current);
    printf("\n=====\n\n");
    printf("Digite a opção desejada: ");
}

void printOrders(Node* list) {
    if (list == NULL) {
        customMessageScreen("Não existe pedido na lista.");
        return;
    }

    clearScreen();
    printf("===== Lista de pedidos =====\n\n");
    printList(list);
    printf("\n=====\n\n");
    printf("Pressione ENTER para voltar a tela inicial...");
    waitForEnter();
}

void printList(Node* current) {
    int count = 0;
    while (current != NULL) {
        count++;
        printf("%d. %s\n", count, current->value);
        current = current->next;
    }
}

void PrintOrderQueue(Queue* queue) {
    if (queue == NULL || queue->count == 0) {
        customMessageScreen("A fila da cozinha está vazia!");
        return;
    }

    clearScreen();
    printf("===== Fila de pedidos =====\n\n");
    doPrintOrderQueue(queue);
    printf("\n=====\n\n");
    getchar();
}

void doPrintOrderQueue(Queue* queue) {
    QueueNode* current = queue->tail;
    int i = queue->count;
    while (current != NULL) {
        printf("Pedido número %d:\n", i--);

        Node* list = current->value;
        while (list != NULL) {
            printf(" - %s\n", list->value);
            list = list->next;
        }
        current = current->next;
    }
}
