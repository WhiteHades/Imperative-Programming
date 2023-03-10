#include <stdio.h>
#include "mefaz_exam1_utils.h"

void init(int size, ParityArray *pointer)
{
    ParityArray ParityArray;
    ParityArray.array = malloc((sizeof(ParityArray) * size));
    ParityArray.odd_idx = size - 1;
    ParityArray.even_idx = 0;
    *pointer = ParityArray;
}

void insert(int number, ParityArray *pointer)
{

    int temp_even = pointer->even_idx;
    int temp_odd = pointer->odd_idx;
    if (number % 2 == 1)
    {
        pointer->array[temp_odd] = number;
        pointer->odd_idx = pointer->odd_idx - 1;
    }

    else if (number % 2 == 0)
    {
        pointer->array[temp_even] = number;
        pointer->even_idx = pointer->even_idx + 1;
    }
}

void destruct(ParityArray *pointer)
{
    free(pointer->array);
    free(pointer);
}

void print(ParityArray *pointer, int size)
{
    printf("\nThe numbers:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Number: %d\n", pointer->array[i]);
    }
    printf("\n");
}

void dump(ParityArray *pointer, char textfile[], int size)
{
    FILE *file = NULL;
    file = fopen(textfile, "w");

    fprintf(file, "\nThe numbers:\n");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "Number: %d\n", pointer->array[i]);
    }
    printf("\nSuccessfully created, written and closed the text file.\n\n");
    fclose(file);
}