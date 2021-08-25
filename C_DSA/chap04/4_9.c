// Linked list stack

#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    int data;
    struct stackNode *link;
};

struct stackNode *top;
struct stackNode *newNode(int element)
{
    struct stackNode *p;
    p = (struct stackNode *)malloc(sizeof(struct stackNode));
    if (p == NULL)
    {
        printf("Memory not enough");
    }
    p->data = element;
    p->link = NULL;
    return p;
}

void pushStack(int element)
{
    struct stackNode *x;
    x = newNode(element);
    if (top == NULL)
    {
        top = x;
    }
    else
    {
        x->link = top;
        top = x;
    }
}

void popStack()
{
    struct stackNode *p;
    if (top == NULL)
    {
        printf("Stack empty");
    }
    else
    {
        p = top;
        top = top->link;
        free(p);
    }
}

void printStack()
{
    struct stackNode *p;
    p = top;
    printf("\n\n");
    while (p != NULL)
    {
        printf("| ");
        printf("%d", p->data);
        printf(" |\n-----\n");
        p = p->link;
    }
}

void main()
{
    pushStack(1);
    pushStack(2);
    pushStack(3);
    pushStack(4);
    printStack();
    popStack();
    popStack();
    printStack();
}