// Stack Data Structure Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// marcro
#define MAXSIZE 5

// global variables
int stack[MAXSIZE];
int top = -1;

int isFull()
{
    if (top == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int element)
{
    if (isFull())
    {
        printf("Stack Full");
    }
    else
    {
        stack[++top] = element;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack Empty");
    }
    else
    {
        stack[top--] = 0;
    }
}

void printStack()
{
    printf("\n\n");
    for (int i = MAXSIZE - 1; i >= 0; i--)
    {
        printf("| ");
        if (top >= i)
        {
            printf("%d", stack[i]);
        }
        printf(" |\n----\n");
    }
}

void main()
{
    memset(stack, 0, sizeof(stack));
    printStack();
    push(5);
    push(1);
    push(2);
    push(2);
    printStack();
    pop();
    pop();
    printStack();
}
