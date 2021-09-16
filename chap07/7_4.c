// merge sort two sorted arrays (bubble sort)

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

void bubbleSort(int array_length, int *input_array)
{
    int temp;
    for (int i = array_length - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (input_array[j - 1] > input_array[j])
            {
                temp = input_array[j - 1];
                input_array[j - 1] = input_array[j];
                input_array[j] = temp;
            }
        }
    }
}

void merge(int *rand_array_c, int *rand_array_a, int array_length_a, int *rand_array_b, int array_length_b)
{
    int i, j, k;
    i = j = k = 0;
    while ((i <= array_length_a) && (j <= array_length_b))
    {
        if (rand_array_a[i] <= rand_array_b[j])
        {
            rand_array_c[k++] = rand_array_a[i++];
        }
        else
        {
            rand_array_c[k++] = rand_array_b[j++];
        }
    }
    while (i <= array_length_a)
    {
        rand_array_c[k++] = rand_array_a[i++];
    }
    while (j <= array_length_b)
    {
        rand_array_c[k++] = rand_array_b[j++];
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
    int rand_array_a[6];
    int array_length_a = sizeof(rand_array_a) / sizeof(rand_array_a[0]);
    generateRandArray(array_length_a, rand_array_a);
    bubbleSort(array_length_a, rand_array_a);
    printf("\nSorted array A:\n");
    printArray(array_length_a, rand_array_a);

    int rand_array_b[8];
    int array_length_b = sizeof(rand_array_b) / sizeof(rand_array_b[0]);
    generateRandArray(array_length_b, rand_array_b);
    bubbleSort(array_length_b, rand_array_b);
    printf("\nSorted array B:\n");
    printArray(array_length_b, rand_array_b);

    
    int *rand_array_c = (int *)malloc((array_length_a + array_length_b + 1) * sizeof(int));
    int array_length_c = array_length_a + array_length_b;

    merge(rand_array_c, rand_array_a, array_length_a, rand_array_b, array_length_b);
    printf("\nMerged sorted array C:\n");
    printArray(array_length_c, rand_array_c);
}