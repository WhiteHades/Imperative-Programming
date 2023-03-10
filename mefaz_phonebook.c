#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct entry
{
    char name[30];
    char num[30];
} typedef entry;

struct phbook
{
    entry *ptr;
    int elements;
    int arrSize;
} typedef phbook;

void init(int size, phbook *pointer);
phbook *destroy(phbook *pointer);
bool insert(char name[], char number[], phbook *phbook);
entry *get(char name[], phbook *phbook);
void print(phbook *pointer);
void dump(phbook *pointer, char textfile[]);

int main()
{
    phbook phbook;
    init(4, &phbook);
    // phbook.elements = 1;
    insert("penss", "111111", &phbook);
    insert("penss", "000000", &phbook);
    phbook.elements = 1;
    insert("paper", "222222", &phbook);
    phbook.elements = 2;
    insert("table", "333333", &phbook);
    phbook.elements = 3;
    insert("chair", "444444", &phbook);
    phbook.elements = 4;

    print(&phbook);
    // printf("%s", get("paper", &phbook));
    entry *getnum = get("paper", &phbook);
    printf("\nProviding a name and retrieving the number:");
    printf("\nName: %s\t", getnum->name);
    printf("Number: %s\n", getnum->num);

    dump(&phbook, "test_phbook.txt");

    destroy(&phbook);

    return 0;
}

void init(int size, phbook *pointer)
{
    phbook phbook;
    phbook.ptr = (entry *)malloc((sizeof(entry) * size));
    phbook.arrSize = size;
    phbook.elements = 0;
    *pointer = phbook;
    // return *pointer;
}

bool insert(char name[], char number[], phbook *phbook)
{
    int i;
    int tempElements = phbook->elements;
    int tempSize = phbook->arrSize;
    // char tempName[] = phbook->ptr[tempElements].name;
    // char *tempName = phbook->ptr[tempElements].name;

    // if (phbook->ptr[tempElements].name != name)
    // {
    //     strcpy(phbook->ptr[tempElements].num, number);
    //     strcpy(phbook->ptr[tempElements].name, name);
    //     return true;
    // }

    // else
    // {
    //     for (i = 0; i < tempElements; i++)
    //     {
    //         // char *tempNameA = phbook->ptr[i].name;
    //         strcpy(phbook->ptr[i].num, number);
    //         return true;
    //     }
    // }
    //
    // return false

    if (tempElements != tempSize)
    {
        for (i = 0; i < tempElements; i++)
        {
            // char *tempNameA = phbook->ptr[i].name;
            if (phbook->ptr[i].name == name)
            {
                strcpy(phbook->ptr[i].num, number);
                return true;
            }
            //     else
            //     {
            //         strcpy(phbook->ptr[tempElements].num, number);
            //         strcpy(phbook->ptr[tempElements].name, name);
            //         return true;
            //     }
        }
        strcpy(phbook->ptr[tempElements].num, number);
        strcpy(phbook->ptr[tempElements].name, name);
        return true;
    }
    else
    {
        return NULL;
    }
}
phbook *destroy(phbook *pointer)
{
    for (int i = 0; i < 4; i++)
    {
        free(pointer->ptr[i].name);
        free(pointer->ptr[i].num);
    }
    free(pointer->ptr);
    free(pointer);
    pointer = NULL;
    pointer->ptr = NULL;
    pointer->elements = 0;
    pointer->arrSize = 0;
    return pointer;
}

entry *get(char name[], phbook *pointer)
{

    // char tempName[] = {pointer->ptr[i].name[0], pointer->ptr[i].name[1], pointer->ptr[i].name[2], pointer->ptr[i].name[3]};
    //     if (tempName == name)
    //     {
    //         // return &(pointer->ptr[i].num);
    //         // return &(pointer->ptr[i]);
    //         return &pointer->ptr[i];
    //     }
    //

    for (int i = 0; i < 4; i++)
    {
        int j = 0;
        for (j = 0; pointer->ptr[i].name[j] != '\0'; j++)
        {
            if (pointer->ptr[i].name[j] != name[j])
            {
                break;
            }
        }
        if (pointer->ptr[i].name[j] == '\0')
        {
            return &pointer->ptr[i];
        }
    }
    return NULL;
}

void print(phbook *pointer)
{
    // int temp = pointer->elements;
    // char number[] = "";
    printf("\nThe entries of the phonebook:\n");
    for (int i = 0; i < 4; i++)
    {
        // strcpy(pointer->ptr[i].name, name);
        // strcpy(pointer->ptr[i].num, number);
        printf("Name: %s\t", pointer->ptr[i].name);
        printf("Number: %s\n", pointer->ptr[i].num);
        // printf("\n");
    }
}

void dump(phbook *pointer, char textfile[])
{
    FILE *file = NULL;
    // char tempName[] = textfile;
    // strcpy(tempName, textfile);
    file = fopen(textfile, "w");

    fprintf(file, "The entries of the phonebook:\n");
    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "Name: %s\t", pointer->ptr[i].name);
        fprintf(file, "Number: %s\n", pointer->ptr[i].num);
    }

    fclose(file);
    printf("\nSuccessfully created, written and closed the text file.\n\n");
}