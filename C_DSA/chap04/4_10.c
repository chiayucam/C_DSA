// Linked list queue

#include <stdio.h>
#include <stdlib.h>

struct queueNode
{
    int data;
    struct queueNode *next;
};

struct queueNode *front, *rear;
struct queueNode *newQueueNode(int element)
{
    struct queueNode *p;
    p = (struct queueNode *)malloc(sizeof(struct queueNode));
    p->data = element;
    p->next = NULL;
    return p;
}

void addQueue(int element)
{
    struct queueNode *p;
    p = newQueueNode(element);
    if (rear == NULL)
    {
        front = p;
    }
    else
    {
        rear->next = p;
    }
    rear = p;
}

void deleteQueue()
{
    struct queueNode *p;
    if (front == NULL)
    {
        printf("Queue empty");
    }
    else
    {
        p = front;
        front = front->next;
        free(p);
    }
}

void printQueue()
{
    struct queueNode *p;
    p = front;
    printf("\n\n");
    while (p != NULL)
    {
        printf("| ");
        printf("%d", p->data);
        printf(" |\n-----\n");
        p = p->next;
    }
}

void main() 
{
    addQueue(1);
    addQueue(2);
    addQueue(3);
    addQueue(4);
    printQueue();
    deleteQueue();
    deleteQueue();
    printQueue();
}