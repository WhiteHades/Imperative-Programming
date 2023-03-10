#include <stdio.h>
#include <stdbool.h>

int main()
{
    int arr1[] = {1, 1, 1, 1, 1};

    int arr2[] = {1, 1, 1, 1, 1};
    int s2 = sizeof(arr2) / sizeof(int);
    int sp = 0;

    for (int i = 0; i < s2; i++)
    {
        sp = sp + (arr1[i] * arr2[i]);
    }
    printf("\nThe weighted sum is %d", sp);

    return 0;
}