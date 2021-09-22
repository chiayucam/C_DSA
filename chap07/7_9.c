// radix sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void radixsort(int arr_length, int arr[])
{
    int *temp;
    int count[10] = {0};
    int index[10] = {0};
    int n = 1;
    int i, j, digit, digit_denominator;
    int radix = 0;
    int max_data = 0;

    temp = (int *)malloc(sizeof(int) * arr_length);

    for (i = 0; i < arr_length; i++)
    {
        if (arr[i] > max_data)
        {
            max_data = arr[i];
        }
    }

    do
    {
        max_data /= 10;
        ++radix;
    } while (max_data != 0);

    digit_denominator = 1;
    for (i = 0; i < radix; i++)
    {
        for (j = 0; j < 10; j++)
        {
            count[j] = 0;
        }
        for (j = 0; j < 10; j++)
        {
            digit = (arr[j] / digit_denominator) % 10;
            count[digit]++;
        }
        index[0] = 0;
        for (j = 1; j < 10; j++)
        {
            index[j] = index[j - 1] + count[j - 1];
        }
        for (j = 0; j < arr_length; j++)
        {

            digit = (arr[j] / digit_denominator) % 10;
            temp[index[digit]++] = arr[j];
        }
        for (j = 0; j < arr_length; j++)
        {
            arr[j] = temp[j];
        }
        digit_denominator *= 10;
    }
}

void main()
{
    int rand_array[10];
    int array_length = sizeof(rand_array) / sizeof(rand_array[0]);
    generateRandArray(array_length, rand_array);
    printf("Random array:\n");
    printArray(array_length, rand_array);
    radixsort(array_length, rand_array);
    printf("\nSorted array:\n");
    printArray(array_length, rand_array);
}