// merge sort (recursive) devide and conquer

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

void merge(int arr[], int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    // create temp arrays
    int *L, *R;
    L = (int *)malloc(n1 * sizeof(int));
    R = (int *)malloc(n2 * sizeof(int));

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // merge temp arrays back into arr
    i = j = 0;
    k = left;
    while ((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }
    // copy remaining elements of L and R if any left
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int left, int right)
{
    int m;
    if (left < right)
    {
        m = (left + right) / 2;
        mergesort(arr, left, m);
        mergesort(arr, m + 1, right);
        merge(arr, left, m, right);
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
    mergesort(rand_array, 0, array_length - 1);
    printf("\nSorted array:\n");
    printArray(array_length, rand_array);
}