/*

In what ways having preprocessor directives in header files
can be useful?

Header files are used mainly to utilise the
system libraries (in this case, of c) and can also be used
for making custom functions that can be used everywhere in
the program.

The main reason why preprocessor directives (where the header
files fall under) is used is because of convenience (for lack
of a better word).

For instance, instead of defining and declaring a function as
a header file everytime one writes code, if the function is
already in the c library (or already written in one file only),
one could easily grab said function by including a header file
such as stdio.h, thereby eliminating the need to go of their
way and writing everytime they want to use it in different programs.

Also, preprocessor directives have utilities like the macros and
the #define.

Also, without using header files in preprocessor directives, if one
writes a function in the middle of the program, one cannot use the
function before it is defined. Using a header file means that the
function is availabe everywhere in the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int num;
    struct node *nextArrow;
} typedef Node;

Node *copy(Node *n);
void message1(Node *n);
void message2(Node *n);

int main(void)
{
    Node *main = (Node *)malloc(sizeof(Node));
    main->num = 1;
    main->nextArrow = NULL;
    Node *second = (Node *)malloc(sizeof(Node));
    second->num = 2;
    second->nextArrow = NULL;
    main->nextArrow = second;
    Node *temp = (Node *)malloc(sizeof(Node));
    message1(main);
    message2(copy(main));
}

Node *copy(Node *n)
{
    //     Node *new = (Node *)malloc(sizeof(Node));
    //     new->num = n->num;
    //     new->nextArrow = copy(n->nextArrow);
    //     return new;
    //

    if (n != NULL)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->num = n->num;
        new->nextArrow = copy(n->nextArrow);
        return new;
    }
    else
    {
        return NULL;
    }

    // Node *temp = n;
    // Node *new = NULL;
    // while (temp != NULL)
    // {
    //     new = (Node *)malloc(sizeof(Node));
    //     new->num = temp->num;
    //     new->nextArrow = NULL;

    //     if (n == NULL)
    //     {
    //         n = new;
    //     }
    //     else
    //     {
    //         n->nextArrow = new;
    //         n = new;
    //     }
    //     temp = temp->nextArrow;
    // }
    // return temp;
}

void message1(Node *n)
{
    printf("The linked list (original):");
    while (n != NULL)
    {
        printf("\nnum: %d\n", n->num);
        // printf("link: %p", n->nextArrow);
        n = n->nextArrow;
    }
    printf("\n");
}

void message2(Node *n)
{
    printf("\nThe linked list (copied):");
    while (n != NULL)
    {
        printf("\nnum: %d\n", n->num);
        // printf("link: %p", n->nextArrow);
        n = n->nextArrow;
    }
}