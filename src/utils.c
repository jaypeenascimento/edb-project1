#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void start() {
    int option;

    homeScreen();
    scanf("%d", &option);
    homeScreenSelection(option);
};

void homeScreen() {
    clearScreen();
    printf("===== Menu =====\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1. Adicionar pedido\n");
    printf("2. Remover pedido\n");
    printf("3. Processar pedido\n");
    printf("4. Listar pedidos (Salão)\n");
    printf("5. Listar pedidos (Cozinha)\n");
    printf("\n=====\n");
}

void platesScreen() {
    clearScreen();
    printf("===== Cardápio =====\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1. Entradas\n");
    printf("2. Pratos Principais\n");
    printf("3. Sobremesas\n");
    printf("\n=====\n");
}

void mainPlatesScreen() {
    clearScreen();
    printf("===== Entradas =====\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n");
    printf("\n=====\n");
}

void appetizersScreen() {
    clearScreen();
    printf("===== Pratos Principais =====\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n");
    printf("\n=====\n");
}

void dessertsScreen() {
    clearScreen();
    printf("===== Sobremesas =====\n\n");
    printf("Digite a opção desejada:\n\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n");
    printf("\n=====\n");
}

void invalidOptionScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Opção inválida!\n\n");
    printf("Pressione ENTER para voltar a tela inicial...\n");
    printf("\n=====\n");
    getchar();
    getchar();
}

void successfullAddScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Adicionado com sucesso!\n\n");
    printf("Pressione ENTER para voltar a tela inicial...\n");
    printf("\n=====\n");
    getchar();
    getchar();
};

void unsuccessfulAddScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Erro ao adicionar\n\n");
    printf("Pressione ENTER para voltar a tela inicial...\n");
    printf("\n=====\n");
    getchar();
    getchar();
};

void notImplementedYetScreen() {
    clearScreen();
    printf("===== \n\n");
    printf("Não implementado ainda\n\n");
    printf("Pressione ENTER para voltar a tela inicial...\n");
    printf("\n=====\n");
    getchar();
    getchar();
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
            // TODO: Método para listar pedidos do salão
            notImplementedYetScreen();
            // scanf("%d", &option);
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
            appetizersScreenSelection(option);
            break;
        case 2:
            mainPlatesScreen();
            scanf("%d", &option);
            mainPlatesScreenSelection(option);
            break;
        case 3:
            dessertsScreen();
            scanf("%d", &option);
            dessertsScreenSelection(option);
            break;
        default:
            invalidOptionScreen();
            getchar();
            getchar();
            break;
    }
}

void appetizersScreenSelection(int option) {
    int APPETIZERS_AMOUNT = 5;

    if (!isAValidOption(option, APPETIZERS_AMOUNT)) {
        invalidOptionScreen();
        return;
    }

    // TODO: Método para adicionar option a lista de pedidos
    notImplementedYetScreen();
}

void mainPlatesScreenSelection(int option) {
    int MAIN_PLATES_AMOUNT = 5;

    if (!isAValidOption(option, MAIN_PLATES_AMOUNT)) {
        invalidOptionScreen();
        return;
    }

    // TODO: Método para adicionar a lista de pedidos
    notImplementedYetScreen();
}

void dessertsScreenSelection(int option) {
    int DESSERTS_AMOUNT = 5;

    if (!isAValidOption(option, DESSERTS_AMOUNT)) {
        invalidOptionScreen();
        return;
    }

    // TODO: Método para adicionar a lista de pedidos
    notImplementedYetScreen();
}

int isAValidOption(int option, int range) {
    return inRange(option, 1, range);
}

int inRange(int val, int min, int max) {
    return val >= min && val <= max;
}
