// shell sort
// shell sort algorithm can choose from different gaps

// basic: N/2, N/4 ... 1
// Hibbard: 2^k-1 ... 7, 3, 1
// Knuth: (3^k-1) / 2 ... 13, 4, 1

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

void printArray(int array_length, int *input_array)
{
    for (int i = 0; i < array_length; i++)
    {
        printf("%d | ", input_array[i]);
    }
}


void shellSort(int array_length, int *input_array)
{
    int j, temp;
    for (int gap = array_length/2; gap>0; gap/=2)
    {
        for (int i = gap; i < array_length; i++)
        {
            temp = input_array[i];
            j = i;
            while ((input_array[j - gap] > temp) && (j > 0))
            {
                input_array[j] = input_array[j - gap];
                j = j - gap;
            }
            input_array[j] = temp;
        }
    printf("\n\n%d Sorted array:\n", gap);
    printArray(array_length, input_array);
    }
}


void main()
{
    int rand_array[8];
    int array_length = sizeof(rand_array) / sizeof(rand_array[0]);
    generateRandArray(array_length, rand_array);
    printf("Random array:\n");
    printArray(array_length, rand_array);
    shellSort(array_length, rand_array);
}