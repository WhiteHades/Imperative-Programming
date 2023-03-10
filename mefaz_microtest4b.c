#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i;
    int j;
    char arr[3][5];
    char arra[3][5];
    char arrb[3][5];

    printf("Enter the elements in the array\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    printf("Original array\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c", arr[i][j]);
        }

        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            arra[i][j] = arr[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {

        for (int k = 0, j = 4; k <= 2, j >= 2; k++, j--)
        {
            arr[i][j] = arra[i][k];
            arr[i][k] = arra[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            arrb[i][j] = arr[i][j];
        }
    }

    for (j = 0; j < 5; j++)
    {
        for (int k = 2, i = 0; i <= 1, k >= 1; i++, k--)
        {
            arr[i][j] = arrb[k][j];
            arr[k][j] = arrb[i][j];
        }

        printf("\n");
    }

    printf("Modified array\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}