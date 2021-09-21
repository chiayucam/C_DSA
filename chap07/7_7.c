// quick sort (recursive) devide and conquer

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandArray(int array_length, int *rand_array)
{
    srand(time(NULL) + array_length);
    for (int i = 0; i < array_length; i++)
    {
        rand_array[i] = rand() % 100;
    }
}

void quicksort(int arr[], int left, int right)
{
    int i, j, temp;
    if (left < right)
    {
        i = left - 1;
        for (j = left; j < right; j++)
        {
            if (arr[j] <= arr[right])
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        quicksort(arr, left, i);
        quicksort(arr, i + 2, right);
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
    int rand_array[16];
    int array_length = sizeof(rand_array) / sizeof(rand_array[0]);
    generateRandArray(array_length, rand_array);
    printf("Random array:\n");
    printArray(array_length, rand_array);
    quicksort(rand_array, 0, array_length - 1);
    printf("\nSorted array:\n");
    printArray(array_length, rand_array);
}