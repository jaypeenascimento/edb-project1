#include "utils.h"
#include "structures/queue.h"
#include "structures/list.h"
#include "screen/screen.h"
#include "screen/selectors.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "options.h"


Node* L = NULL;
Queue* OrderQueue = NULL;

void start() {
    int option;
    customScreen("Menu", HOME_MENU, HOME_MENU_SIZE);
    scanf("%d", &option);
    waitForEnter();
    homeScreenSelection(option);
}

struct Node* removeOrder(struct Node* head, int position) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    flushInput();

    if (temp == NULL) {
        customMessageScreen("Não existe pedido na lista.");
        return head;
    }

    if (position == 1) {
        head = temp->next;
        free(temp);
        customMessageScreen("Removido com sucesso.");
        return head;
    }

    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
        customMessageScreen("Removido com sucesso.");
    } else {
        customMessageScreen("Opção inválida");
    }

    return head;
}

void ProcessOrder() {
    if (L == NULL) {
        customMessageScreen("Não foi possível processar o pedido: Lista do salão está vazia.");
        return;
    }

    doProcessOrder();
    customMessageScreen("Pedido adicionado a fila da cozinha!");
}

void doProcessOrder() {
    if (OrderQueue == NULL) {
        OrderQueue = NewQueue();
    }

    QueueNode* node = NewNode(L);
    Enqueue(OrderQueue, node);
    L = NULL;
}

void waitForEnter() {
    getchar();
}

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
