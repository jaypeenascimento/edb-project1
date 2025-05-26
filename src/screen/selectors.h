#ifndef SELECTORS_H
#define SELECTORS_H

#include <stdbool.h>

void homeScreenSelection(int option);
void platesScreenSelection(int option);
void appetizersScreenSelection(int option);
void mainPlatesScreenSelection(int option);
void dessertsScreenSelection(int option);

bool checkIsAValidOption(int option, int amount);
int isAValidOption(int option, int range);
int inRange(int val, int min, int max);

#endif
