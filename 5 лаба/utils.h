#ifndef UTILS_H_   /* Include guard */
#define UTILS_H_
#include <stddef.h>

void printLogo();
char *get_str();
void insertRowByIndex(int **matrix, int length);
void insertColumnByIndex(int **matrix, int length);
void deleteRowByIndex(int **matrix, int length);
void deleteColumnByIndex(int **matrix, int length);
void getCofactor(int **matrix, int **temp, int p, int q, int n);
int calculateMinors(int **matrix, int n);

#endif // UTILS_H_