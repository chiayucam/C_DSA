// insert node to max heap as array

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int heap[MAXSIZE];
int n, i;

void insertHeap(int x)
{
    if (n == MAXSIZE)
    {
        printf("Heap full");
    }
    else
    {
        n++;
        i = n;
        while ((i > 1) && (x > heap[i / 2]))
        {
            heap[i] = heap[i / 2];
            i /= 2;
        }
        heap[i] = x;
    }
}

void initializeArray()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        heap[i] = -1;
    }
}

void main()
{
    initializeArray();
    insertHeap(5);
    insertHeap(2);
    insertHeap(6);
    insertHeap(3);
    insertHeap(9);
    insertHeap(4);
    for (int i = 0; i<MAXSIZE; i++)
    {
        if (heap[i] != -1)
        {
            printf("%d-[%d]\n", heap[i], i);
        }
    }
}