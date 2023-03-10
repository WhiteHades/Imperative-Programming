#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("Hello world - %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("arg %d - %s, %i, %f\n", i, argv[i], atoi(argv[i]), atof(argv[i]));
    }
}