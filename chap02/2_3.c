#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int data[], int dataLength, int n)
{
    int i, j;
    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        swap(&data[i], &data[min]);
    }
    for (i = 0; i < dataLength; i++)
    {
        printf("%d ", data[i]);
    }
}

void main()
{
    int data[] = {2, 55, 4, 14, 84, 45};
    int dataLength = sizeof(data) / sizeof(data[0]);
    SelectionSort(data, dataLength, 6);
}