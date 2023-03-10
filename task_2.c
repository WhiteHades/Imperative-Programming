#include <stdio.h>
#include <stdbool.h>

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
    int min = 0;

    for (int i = 0; i < n; i++)
    {
        if (e[i] > max)
        {
            max = e[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (e[i] < min)
        {
            min = e[i];
        }
    }

    // int length = sizeof(e) / sizeof(e[0]);
    int index_max = 0;
    int index_min = 0;

    for (int i = 0; i < n; i++)
    {
        if (e[i] == max)
        {
            index_max = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (e[i] == min)
        {
            index_min = i;
        }
    }

    e[index_max] = min;
    e[index_min] = max;

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", e[i]);
    }
}