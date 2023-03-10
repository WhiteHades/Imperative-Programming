#include <string.h>
#include "reverse.h"

void reverse(char *str)
{
    int length = 0;
    while (str[length])
    {
        ++length;
    }
    for (int i = 0; i < length / 2; i++)
    {
        char temporary = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temporary;
    }
}