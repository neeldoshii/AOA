#include <stdio.h>
#include <conio.h>

void Merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int aL[50], aR[50];

    for (int i = 0; i < n1; i++)
    {
        aL[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++)
    {
        aR[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (aL[i] < aR[j])
        {
            arr[k] = aL[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = aR[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = aL[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = aR[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[5] = {50, 40, 30, 20, 10};
    int size = 5;
    mergeSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}