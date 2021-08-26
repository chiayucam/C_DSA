// invert linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *first, *last;

void attachDataToList(int element)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = element;
    p->link = NULL;
    if (first == NULL)
    {
        first = last = p;
    }
    else
    {
        last->link = p;
        last = p;
    }
}

void invert()
{
    struct node *r, *s, *t;
    r = first;
    s = NULL;
    last = r;
    while (r != NULL)
    {
        t = s;
        s = r;
        r = r->link;
        s->link = t;
    }
    first = s;
}

void printLinkedList()
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
    attachDataToList(1);
    attachDataToList(2);
    attachDataToList(3);
    attachDataToList(4);
    printLinkedList();
    invert();
    printLinkedList();
}