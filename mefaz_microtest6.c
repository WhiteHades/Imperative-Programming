#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Structure and union are similar but not exactly the same, in that, they share the basic format,
which is, they take custom data types accordng to the user; the data types (memebers) could be
like or unlike. The 'not exactly the same' are explained briefly below.

In terms of size, a union (wholly) attains the size of the member that has the highest memory
size in that given architecture, whereas, the size of structures are cumulative in nature; sizes
add up with each member added, atleast.

In terms of allocation, the variables with the given data types (members) in union share their
addresses, i.e., location of where their memory is stored. But, members in structures have their
own designated memory locations.

This one is kind of a tautology because structure is initilised by writing 'struct' and then
a name and union is initialised by writing 'union' and then a name.
*/

struct rectangles
{
    double b;
    double h;
} typedef rectangles;

// double perimeter(double b, double h);
double perimeter(rectangles peri);
double area(rectangles *peri);
void edit(rectangles *peri, double x, double y);

int main()
{
    struct rectangles peri;
    printf("Please state the rectangle base length: ");
    scanf("%lf", &peri.b);
    printf("Please state the rectangle height length: ");
    scanf("%lf", &peri.h);

    // printf("base: %.2lf\n", peri.b);
    // printf("height: %.2lf", peri.h);

    double pr2 = perimeter(peri);
    double ar2 = area(&peri);

    printf("Perimeter is: %.2lf", pr2);
    printf("\nArea is: %.2lf", ar2);

    edit(&peri, 5.5, 6.6);

    printf("\n\nAfter editing the given data:");
    printf("\nBase: %.2lf", peri.b);
    printf("\nHeight: %.2lf", peri.h);

    return 0;
}

double perimeter(rectangles peri)
{
    double pr = 2 * (peri.b) + 2 * (peri.h);
    return pr;
}
double area(rectangles *peri)
{
    double ar = (peri->b) * (peri->h);
    return ar;
}
void edit(rectangles *peri, double x, double y)
{
    (*peri).b = x;
    (*peri).h = y;
}
