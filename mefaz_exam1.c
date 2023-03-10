#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mefaz_exam1_utils.h"
// #include "mefaz_exam1_utils.c"
#define ARRAY_SIZE 10

int main()
{
    ParityArray ParityArray;
    int length = 0;
    printf("Input total array length: ");
    scanf("%d", &length);
    init(length, &ParityArray);

    for (int i = 0; i < length; i++)
    {
        int length2;
        printf("Input the numbers: ");
        scanf("%d", &length2);
        insert(length2, &ParityArray);
    }

    print(&ParityArray, length);
    dump(&ParityArray, "mefaz_exam1.txt", length);
    destruct(&ParityArray);

    return 0;
}