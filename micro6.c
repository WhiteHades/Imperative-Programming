#include <stdio.h>
#include <string.h>
#define N 1

struct employee
{
    char name[2];
    int id;
} typedef employee;

employee data[2];

employee enrol(char x[], int y);
employee enrol2(char x[], int y);

void fire(int id)
{
    for (int i = 0; i < N; i++)
    {
        if (data[i].id == id)
        {
            data[i].id = -1;
            // printf("\n%d", data[i].id);
        }
    }
}

int main()
{
    // struct employee number1;
    int number1id;
    int number2id;
    char number1name[50];
    char number2name[50];

    // for (int i = 0; i < N; i++)
    //{
    // }
    printf("Please state the employee name 1: ");
    scanf("%s", number1name);
    printf("Please state the employee id 1: ");
    scanf("%d", &number1id);

    printf("Please state the employee name 2: ");
    scanf("%s", number2name);
    printf("Please state the employee id 2: ");
    scanf("%d", &number2id);

    enrol(number1name, number1id);
    enrol2(number2name, number2id);

    fire(45);
}

employee enrol(char x[], int y)
{
    struct employee number1;
    strcpy(number1.name, x);
    number1.id = y;
    data[0] = number1;
}

employee enrol2(char x[], int y)
{
    struct employee number2;
    strcpy(number2.name, x);
    number2.id = y;
    data[N] = number2;
}