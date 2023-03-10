#include <stdio.h>
#include <stdbool.h>

// Write a program that takes as input the size of an array, and the elements to fill it, then finds both
// the maximum and the minimum

int main()
{
    int n;
    printf("State the size of the array: ");
    scanf("%d", &n);

    int e[n];

    for (int i = 0; i < n; i++)
    {
        printf("Write the element of the array, %d: ", i + 1);
        scanf("%d", &e[i]);
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (e[i] > max)
        {
            max = e[i];
        }
    }
    printf("%d", max);
}