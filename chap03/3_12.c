// Circular Queue Data Structure Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 12

int CQ[MAXSIZE];
int front = 0;
int rear = 0;

int isCQEmpty()
{
    if (rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isCQFull()
{
    if ((rear + 1) % MAXSIZE == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void addCQ(int element)
{
    if (isCQFull())
    {
        printf("Circular queue full");
    }
    else
    {
        CQ[++rear % MAXSIZE] = element;
    }
}

void deleteCQ()
{
    if (isCQEmpty())
    {
        printf("Circular queue empty");
    }
    else
    {
        CQ[++front % MAXSIZE] = 0;
    }
}

void printCQ()
{
    int rowFirstElement, rowSecondElement;
    int spacingMultiplier = 3;
    float checkpoint = (float)MAXSIZE / 4.;

    printf("\n\n");
    for (int i = 0; i < MAXSIZE / 2 + 1; i++)
    {
        rowFirstElement = (MAXSIZE - i) % MAXSIZE;
        rowSecondElement = i;
        if (rowFirstElement == rowSecondElement)
        {
            printf("%*c", spacingMultiplier * MAXSIZE / 2, ' ');
            printf("%d\n", CQ[rowFirstElement]);
        }
        else
        {
            if ((float)i < checkpoint)
            {
                printf("%*c", spacingMultiplier * (MAXSIZE / 2 - i), ' ');
                printf("%d", CQ[rowFirstElement]);
                printf("%*c", spacingMultiplier * 2 * i - 1, ' ');
            }
            else
            {
                printf("%*c", spacingMultiplier * i, ' ');
                printf("%d", CQ[rowFirstElement]);
                printf("%*c", spacingMultiplier * 2 * (MAXSIZE / 2 - i) - 1, ' ');
            }
            printf("%d\n", CQ[rowSecondElement]);
        }
    }
    printf("front at %d\n", CQ[front+1]);
    printf("rear at %d\n", CQ[rear]);
}

void main()
{
    memset(CQ, 0, sizeof(CQ));
    printCQ();
    addCQ(1);
    addCQ(2);
    addCQ(3);
    addCQ(4);
    addCQ(5);
    addCQ(6);
    addCQ(7);
    addCQ(8);
    addCQ(9);
    printCQ();
    deleteCQ();
    deleteCQ();
    printCQ();
    deleteCQ();
    deleteCQ();
    printCQ();
}