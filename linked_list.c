#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct charNode
{
    char data;
    struct charNode *nxtNode;
};

typedef struct charNode Node;

void printlist(Node *currentPtr);
void insert(Node **sPtr, char value);
void delete (Node **sPtr, char value);

int main(void)
{
    Node *root = (Node *)malloc(sizeof(Node));

    root->data = 'c';
    root->nxtNode = NULL;

    insert(&root, 'f');
    printlist(root);
    /*
    Node *second = (Node *)malloc(sizeof(Node));
    second->data = 'a';
    second->nxtNode = NULL;

    root->nxtNode = second;
    */
}

// print the list
void printlist(Node *currentPtr)
{
    if (currentPtr == NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is:\n");

        // while not the end of the list
        while (currentPtr != NULL)
        {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nxtNode;
        } // end while

        printf("NULL\n\n");
    } // end else
} // end function printlist

// insert in list
void insert(Node **sPtr, char value)
{
    Node *newPtr;      // pointer to new node
    Node *previousPtr; // pointer to previous node in list
    Node *currentPtr;  // pointer to current node in list

    newPtr = (Node *)malloc(sizeof(Node));

    if (newPtr != NULL) // is space availabe?
    {
        newPtr->data = value;   // place value in node
        newPtr->nxtNode = NULL; // node does not link another node

        previousPtr = NULL;
        currentPtr = *sPtr; // begin at the root

        while (currentPtr != NULL)
        {
            previousPtr = currentPtr;         // walk to...
            currentPtr = currentPtr->nxtNode; // ... next node
        }
        previousPtr->nxtNode = newPtr;
    } // end if

    else
    {
        printf("%c not inserted. No memory available.\n", value);
    } // end else
} // end function insert