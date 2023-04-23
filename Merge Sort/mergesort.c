#include <stdio.h>
#include <conio.h>

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void Merge(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int aL[20], aR[20];

    for (int i = 0; i < n1; i++)
    {
        aL[i] = a[low + i]; // low 0 h a[]
    }

    for (int j = 0; j < n2; j++)
    {
        aR[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (aL[i] < aR[j])
        {
            a[k] = aL[i];
            k++;
            i++;
        }
        else
        {
            a[k] = aR[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        a[k] = aL[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = aR[j];
        k++;
        j++;
    }
}
void mergesort(int a[], int low, int high)
{

    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main()
{

    int a[100];
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        int temp;
        printf("Enter number : ");
        scanf("%d", &temp);
        a[i] = temp;
    }

    printf("Before sorting \n");
    printArray(a, size);
    printf("After sorting \n");
    mergesort(a, 0, size - 1);

    printArray(a, size);
}