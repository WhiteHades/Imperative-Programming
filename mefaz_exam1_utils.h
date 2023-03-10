#ifndef mefaz_header
#define mefaz_header

#include <stdio.h>

#define ARRAY_SIZE 10

struct ParityArray
{
    int *array;
    int even_idx;
    int odd_idx;
} typedef ParityArray;
void init(int size, ParityArray *pointer);
void insert(int number, ParityArray *pointer);
void destruct(ParityArray *pointer);
void print(ParityArray *pointer, int size);
void dump(ParityArray *pointer, char textfile[], int size);
#endif