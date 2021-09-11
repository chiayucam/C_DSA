// delete node from max heap as array

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

void deleteHeap()
{
    int x, i, j;
    if (n == 0)
    {
        printf("Heap empty");
    }
    else
    {
        x = heap[1];
        n--;
        i = 1;
        while (i <= n / 2)
        {
            if (heap[2 * i] > heap[2 * i + 1])
            {
                j = 2 * i;
            }
            else
            {
                j = 2 * i + 1;
            }
            heap[i] = heap[j];
            i = j;
        }
        heap[i] = heap[n + 1];
        heap[n + 1] = -1;
    }
}

void initializeArray()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        heap[i] = -1;
    }
}

void printHeap()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (heap[i] != -1)
        {
            printf("%d-[%d]\n", heap[i], i);
        }
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
    insertHeap(1);
    printHeap();
    deleteHeap();
    printHeap();
}