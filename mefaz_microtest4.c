#include <stdio.h>
#include <stdbool.h>

int main()
{
    int arr[999];
    int *p = arr;
    int n;
    int max = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (p + i));
    }

    printf("The array elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    for (int i = 0; i < n; i++)
    {
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
    }

    printf("\n");

    printf("Modified array: ");
    for (int i = 0; i < n; i++)
    {
        *(p + i) = max;
        printf("%d ", *(p + i));
    }

    return 0;
}