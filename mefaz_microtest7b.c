/*

Why is manual deallocation needed when dealing with dynamically
allocated memory (malloc, etc.)?

When memory is dynamically allocated through malloc (among others),
it needs to be deallocated manually when its usage is over.
Because, if it isn't deallocated, it results in a leakage of
memory (memory leak). This can cause unwanted issues such
as reducing the processing prowess of a "low-end" device,
taking up spaces/memory that otherwise could have been used in
other areas of process, there not being sufficient contiguous
memory in the system heap for further allocation of data, etc.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int num;
    struct node *next;
} typedef Node;

Node *destroy(Node *n);
void message1(Node *n);
void message2(Node *n);

int main(void)
{
    Node *main = (Node *)malloc(sizeof(Node));
    main->num = 1;
    main->next = NULL;
    Node *second = (Node *)malloc(sizeof(Node));
    second->num = 2;
    second->next = NULL;
    main->next = second;
    message1(main);
    message2(destroy(main));
}

Node *destroy(Node *n)
{
    Node *helper = n;
    while (helper != NULL)
    {
        helper = helper->next;
        free(n);
        n = helper;
    }
    return n;
}

void message1(Node *n)
{
    printf("The linked list before getting destroyed:");
    while (n)
    {
        printf("\nvalue: %d\n", n->num);
        printf("Next: %p\n", n->next);
        // printf("\n");
        n = n->next;
    }
}

void message2(Node *n)
{
    if (n == NULL)
    {
        printf("\nThe linked list has been destroyed.\n\n");
    }
}
