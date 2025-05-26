#include "selectors.h"
#include "screen.h"
#include "../utils.h"
#include "../options.h"
#include "../structures/list.h"

#include <stdbool.h>
#include <stdio.h>

extern Node* L;
extern Queue* OrderQueue;

void homeScreenSelection(int option) {
    switch (option) {
        case 1:
            customScreen("Cardápio", PLATES_MENU, PLATES_MENU_SIZE);
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
            PrintOrderQueue(OrderQueue);
            break;
        default:
            customMessageScreen("Opção inválida");
            break;
    }
}

void platesScreenSelection(int option) {
    switch (option) {
        case 1:
            customScreen("Entradas", APPETIZERS, APPETIZERS_SIZE);
            scanf("%d", &option);
            waitForEnter();
            appetizersScreenSelection(option);
            break;
        case 2:
            customScreen("Pratos Principais", MAIN_PLATES, MAIN_PLATES_SIZE);
            scanf("%d", &option);
            waitForEnter();
            mainPlatesScreenSelection(option);
            break;
        case 3:
            customScreen("Sobremesas", DESSERTS, DESSERTS_SIZE);
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
    bool isValid = checkIsAValidOption(option, APPETIZERS_SIZE);
    if (!isValid) {
        customMessageScreen("Opção inválida");
        return;
    }
    insertAtEnd(&L, APPETIZERS[option - 1]);
    customMessageScreen("Adicionado com sucesso!");
}

void mainPlatesScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, MAIN_PLATES_SIZE);
    if (!isValid) {
        customMessageScreen("Opção inválida");
        return;
    }
    insertAtEnd(&L, MAIN_PLATES[option - 1]);
    customMessageScreen("Adicionado com sucesso!");
}

void dessertsScreenSelection(int option) {
    bool isValid = checkIsAValidOption(option, DESSERTS_SIZE);
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
