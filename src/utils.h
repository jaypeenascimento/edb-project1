#ifndef UTILS_H
#define UTILS_H

void start();

// Métodos de Exibição de tela

void homeScreen();

void platesScreen();

void mainPlatesScreen();

void appetizersScreen();

void dessertsScreen();

void invalidOptionScreen();

void successfullyAddedScreen();

void successfullAddScreen();

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

int isAValidOption(int option, int range);

int inRange(int val, int min, int max);

#endif