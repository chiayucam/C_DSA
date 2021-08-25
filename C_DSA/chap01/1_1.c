#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int data[], int data_length, int n)
{
    int i, j;
    int min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (data[j] < data[min])
            {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
    for (i = 0; i < data_length; i++)
    {
        printf("%d ", data[i]);
    }
}

int main()
{
    int data[] = {12, 44, 26, 38, 10, 1, 2, 41, 55, 21};
    int data_length = sizeof(data) / sizeof(data[0]);
    SelectionSort(data, data_length, 5);
}