#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils_practise.h"

void read(int arr[], int val, int i)
{ // i = slot being used
	if (i < 10)
		arr[i] = val;
}

void print(int arr[], int s, int i)
{
	if (i < s)
		printf("Value at %d: %d\n", i, arr[i]);
}

void add(int arr[], int s, int op1, int op2, int iRes)
{
	if (op1 < s && op2 < s && iRes < s)
		arr[iRes] = arr[op1] + arr[op2];
}

void sub(int arr[], int s, int op1, int op2, int iRes)
{
	if (op1 < s && op2 < s && iRes < s)
		arr[iRes] = arr[op1] - arr[op2];
}

void mul(int arr[], int s, int op1, int op2, int iRes)
{
	if (op1 < s && op2 < s && iRes < s)
		arr[iRes] = arr[op1] * arr[op2];
}

void my_div(int arr[], int s, int op1, int op2, int iRes)
{
	if (op1 < s && op2 < s && iRes < s)
		if (arr[op2])
			arr[iRes] = arr[op1] / arr[op2];
}

int sum(int *arr, int s)
{
	int res = 0;

	for (int i = 0; i < s; i++)
		res += *(arr + i);

	return res;
}

double avg(int *arr, int s)
{
	double res = 0;

	for (int i = 0; i < s; i++)
		res += arr[i];

	return res / s;
}

int main()
{
	// int buffer[10], s = sizeof(buffer)/sizeof(int); // have to put it in the heap
	int *buffer, s = 10;

	// buffer = (int*)malloc(10*sizeof(int));
	// memset(buffer, 0, 10*sizeof(int));

	// for(int i = 0; i<10; i++)
	// buffer[i] = 0;

	buffer = (int *)calloc(10, sizeof(int));

	FILE *fp = fopen("ops.txt", "r");
	char op[6];
	int op1, op2, res;

	// for(int i = 0; i<7; i++){
	while (fscanf(fp, "%s", op) == 1)
	{
		// if(fscanf(fp, "%s", op) == 1){
		if (!strcmp(op, "read"))
		{
			fscanf(fp, "%d %d", &op1, &op2);
			read(buffer, op1, op2);
		}
		else if (!strcmp(op, "print"))
		{
			fscanf(fp, "%d", &op1);
			print(buffer, s, op1);
		}
		else if (!strcmp(op, "add"))
		{
			fscanf(fp, "%d %d %d", &op1, &op2, &res);
			add(buffer, s, op1, op2, res);
		}
		else if (!strcmp(op, "sub"))
		{
			fscanf(fp, "%d %d %d", &op1, &op2, &res);
			sub(buffer, s, op1, op2, res);
		}
		else if (!strcmp(op, "mul"))
		{
			fscanf(fp, "%d %d %d", &op1, &op2, &res);
			mul(buffer, s, op1, op2, res);
		}
		else if (!strcmp(op, "div"))
		{
			fscanf(fp, "%d %d %d", &op1, &op2, &res);
			my_div(buffer, s, op1, op2, res);
		}
		//}
	}

	printf("Sum of the buffer: %d\n", sum(buffer, s));
	printf("Average of the buffer: %.2lf\n", avg(buffer, s));

	fclose(fp);
	// printf("%d", buffer[0]);
	free(buffer);
}
