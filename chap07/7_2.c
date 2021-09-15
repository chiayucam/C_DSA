// bubble sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandArray(int array_length, int *rand_array)
{
    srand(time(NULL));
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
        for (int j=1; j<=i; j++)
        {
            if (input_array[j-1]>input_array[j])
            {
                temp = input_array[j-1];
                input_array[j-1] = input_array[j];
                input_array[j] = temp;
            }
        }
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
    bubbleSort(array_length, rand_array);
    printf("\n\nSorted array:\n");
    printArray(array_length, rand_array);
}