#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H

char* HOME_MENU[] = {
    "Adicionar pedido",
    "Remover pedido",
    "Processar pedido",
    "Listar pedidos (Salão)",
    "Listar pedidos (Cozinha)"
};

char* PLATES_MENU[] = {
    "Entradas",
    "Pratos Principais",
    "Sobremesas"
};

char* APPETIZERS[] = {
    "Sopa de Cebola",
    "Salada Caesar",
    "Bruschetta",
    "Carpaccio de Carne",
    "Camarão ao Alho"
};

char* MAIN_PLATES[] = {
    "Lasanha à Bolonhesa",
    "Filé Mignon com Fritas",
    "Frango Grelhado com Legumes",
    "Bacalhau à Gomes de Sá",
    "Risoto de Cogumelos"
};

char* DESSERTS[] = {
    "Tiramisu",
    "Cheesecake de Frutas Vermelhas",
    "Mousse de Chocolate",
    "Pudim de Leite",
    "Sorvete de Baunilha com Calda de Morango"
};

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

#endif
