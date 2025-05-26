#include "utils.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures/queue.h"

#include "options.c"

Node* L = NULL;
Queue* OrderQueue = NULL;

void start() {
    int option;
    customScreen("Menu", HOME_MENU, ARRAY_LENGTH(HOME_MENU));
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

void emptyOrderList() {
  Node* current = L;
  while (current != NULL) {
    Node* tmp = current;
    current = current->next;
    free(tmp);
  }

  L = NULL;
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
    Node* current = list;

    if (list == NULL) {
        customMessageScreen("Não existe pedido na lista.");
        return;
    }

    clearScreen();
    printf("===== Lista de pedidos =====\n\n");
    printList(current);
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

void ProcessOrder() {
  if (L == NULL) {
    customMessageScreen("Não foi possível processar o pedido: Lista do salão está vazia.");
    return;
  }

  doProcessOrder();
  customMessageScreen("Pedido adicionado a fila da cozinha!");
}

void doProcessOrder() {
  // Start queue if it's null.
  if (OrderQueue == NULL) {
    OrderQueue = NewQueue();
  }

  QueueNode* node = NewNode(L);
  Enqueue(OrderQueue, node);

  L = NULL;
}

void PrintOrderQueue() {
    if (OrderQueue == NULL) {
      OrderQueue = NewQueue();
    }
    if (OrderQueue->count == 0) {
      customMessageScreen("A fila da cozinha está vazia!");
      return;
    }

    clearScreen();
    printf("===== Fila de pedidos =====\n\n");
    doPrintOrderQueue();
    printf("\n=====\n\n");
    waitForEnter();
}

void doPrintOrderQueue() {
  // Start queue if it's null.
  if (OrderQueue == NULL) {
    OrderQueue = NewQueue();
  }

  QueueNode* current = OrderQueue->tail;
  int i = OrderQueue->count;
  while (current != NULL) {
    printf("Pedido número %d:\n", i);
    i--;

    Node* list = current->value;
    while (list != NULL) {
        printf(" - %s\n", list->value);
        list = list->next;
    }
    current = current->next;
  }
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
            customScreen("Cardápio", PLATES_MENU, ARRAY_LENGTH(PLATES_MENU));
            scanf("%d", &option);
            waitForEnter();
            platesScreenSelection(option);
            break;
        case 2:
            printOrdersForRemove(L);
            scanf("%d", &option);
            L = removeOrder(L, option);
            break;
        case 3:
            ProcessOrder();
            break;
        case 4:
            printOrders(L);
            break;
        case 5:
            PrintOrderQueue();
            break;
        default:
            customMessageScreen("Opção inválida");
            break;
    }
}

void platesScreenSelection(int option) {
    switch (option) {
        case 1:
            customScreen("Entradas", APPETIZERS, ARRAY_LENGTH(APPETIZERS));
            scanf("%d", &option);
            waitForEnter();
            appetizersScreenSelection(option);
            break;
        case 2:
            customScreen("Pratos Principais", MAIN_PLATES,
                         ARRAY_LENGTH(MAIN_PLATES));
            scanf("%d", &option);
            waitForEnter();
            mainPlatesScreenSelection(option);
            break;
        case 3:
            customScreen("Sobremesas", DESSERTS, ARRAY_LENGTH(DESSERTS));
            scanf("%d", &option);
            waitForEnter();
            dessertsScreenSelection(option);
            break;
        default:
            customMessageScreen("Opção inválida");
            break;
    }
}

void appetizersScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(APPETIZERS));
    if (!isValid) {
        customMessageScreen("Opção inválida");
        return;
    }

    insertAtEnd(&L, APPETIZERS[option - 1]);
    customMessageScreen("Adicionado com sucesso!");
}

void mainPlatesScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(MAIN_PLATES));
    if (!isValid) {
        customMessageScreen("Opção inválida");
        return;
    }

    insertAtEnd(&L, MAIN_PLATES[option - 1]);
    customMessageScreen("Adicionado com sucesso!");
}

void dessertsScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, ARRAY_LENGTH(DESSERTS));
    if (!isValid) {
        customMessageScreen("Opção inválida");
        return;
    }

    insertAtEnd(&L, DESSERTS[option - 1]);
    customMessageScreen("Adicionado com sucesso!");
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

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
