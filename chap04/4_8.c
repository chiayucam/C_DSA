#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct node
{
    int data;
    struct node *link;
};

struct node *a_first, *b_first, *c_first;

struct node *concatenate(struct node *a_first, struct node *b_first)
{
    struct node *p;
    if (a_first == NULL)
    {
        return b_first;
    }
    else
    {
        for (p = a_first; p->link != NULL; p = p->link)
        {
        }
        p->link = b_first;
        return a_first;
    }
}

struct node *createLinkedList(int arg_count, ...)
{
    va_list arg_list;
    struct node *p, *first, *last;
    va_start(arg_list, arg_count);
    for (int i = 0; i < arg_count; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = va_arg(arg_list, int);
        p->link = NULL;
        if (i == 0)
        {
            first = last = p;
        }
        else
        {
            last->link = p;
            last = p;
        }
    }
    va_end(arg_list);
    return first;
}

void printLinkedList(struct node *first)
{
    struct node *p;
    p = first;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("\n");
}

void main()
{
    int arg_count = 4;
    a_first = createLinkedList(arg_count, 1, 2, 3, 4);
    b_first = createLinkedList(arg_count, 5, 6, 7, 8);
    printLinkedList(a_first);
    printLinkedList(b_first);
    c_first = concatenate(a_first, b_first);
    printLinkedList(c_first);
}