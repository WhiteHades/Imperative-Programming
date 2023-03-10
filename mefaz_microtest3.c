#include <stdio.h>
#include <stdbool.h>

int main()
{
    float n;
    scanf("%f", &n);
    float nums[] = {5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    float s = sizeof(nums) / sizeof(int);
    float sum = 0;

    if (n < s)
    {
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        float average = sum / n;
        printf("%f", average);
    }

    return 0;
}