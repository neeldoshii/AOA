#include <stdio.h>
#include <conio.h>

int main()
{
    int size = 10;
    int low = 0, high = size - 1, mid;
    // binary search always works in a sorted array //Remember
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int key = 30;
    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("%d \n", mid);
        if (arr[mid] > key)
        {

            high = mid - 1;
        }

        if (arr[mid] < key)
        {
            low = mid + 1;
        }

        if (arr[mid] == key)
        {
            printf("Found at %d", mid);
            break;
        }
    }

    return 0;
}