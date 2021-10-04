// heap sort

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n , largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n/2 -1; i>=0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void generateRandArray(int array_length, int *rand_array)
{
    srand(time(NULL) + array_length);
    for (int i = 0; i < array_length; i++)
    {
        rand_array[i] = rand() % 1000;
    }
}

void printArray(int array_length, int *input_array)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%d | ", input_array[i]);
    }
}

void main()
{
    int rand_array[10];
    int array_length = sizeof(rand_array) / sizeof(rand_array[0]);
    generateRandArray(array_length, rand_array);
    printf("Random array:\n");
    printArray(array_length, rand_array);
    heapsort(rand_array, array_length);
    printf("\nSorted array:\n");
    printArray(array_length, rand_array);
}
