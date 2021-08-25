#include <stdio.h>
#include <stdlib.h>

int binarySearch(int data[], int x, int left, int right, int searchCount)
{
    searchCount += 1;
    printf("search count: %d\n", searchCount);
    int mid;
    if (left <= right)
    {
        mid = (left + right) / 2;
        printf("left: %d mid: %d right: %d\n", left, mid, right);
        if (data[mid] == x)
        {
            return mid;
        }
        if (data[mid] < x)
        {
            printf("mid < X < right\n");
            return binarySearch(data, x, mid + 1, right, searchCount);
        }
        else
        {
            printf("left < X < mid\n");
            return binarySearch(data, x, left, mid - 1, searchCount);
        }
    }
    return -1;
}

void main()
{
    int data[] = {2, 14, 25, 26, 32, 43, 62, 71, 76, 85, 88, 95, 98};
    int x = 89;
    int pos = binarySearch(data, x, 0, sizeof(data) / sizeof(data[0]) - 1, 0);

    if (pos == -1)
    {
        printf("Cannot find X in array");
    }
    else
    {
        printf("Found X at position:");
        printf("%d", pos);
    }
}