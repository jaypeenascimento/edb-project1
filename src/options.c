#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H

static const char* const HOME_MENU[] = {
    "Adicionar pedido",
    "Remover pedido",
    "Processar pedido",
    "Listar pedidos (Salão)",
    "Listar pedidos (Cozinha)"
};

static const char* const PLATES_MENU[] = {
    "Entradas",
    "Pratos Principais",
    "Sobremesas"
};

static const char* const APPETIZERS[] = {
    "Sopa de Cebola",
    "Salada Caesar",
    "Bruschetta",
    "Carpaccio de Carne",
    "Camarão ao Alho"
};

static const char* const MAIN_PLATES[] = {
    "Lasanha à Bolonhesa",
    "Filé Mignon com Fritas",
    "Frango Grelhado com Legumes",
    "Bacalhau à Gomes de Sá",
    "Risoto de Cogumelos"
};

static const char* const DESSERTS[] = {
    "Tiramisu",
    "Cheesecake de Frutas Vermelhas",
    "Mousse de Chocolate",
    "Pudim de Leite",
    "Sorvete de Baunilha com Calda de Morango"
};

#define ARRAY_LENGTH(arr) (sizeof(arr) / sizeof((arr)[0]))

#endif
