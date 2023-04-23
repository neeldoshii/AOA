#include <stdio.h>
#include <conio.h>

void quicksort(int arr[], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (arr[i] < arr[pivot] && i < last)
            {
                i++;
            }

            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main()
{
    int arr[5] = {10, 30, 50, 20, 40};
    int size = 5;

    quicksort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}