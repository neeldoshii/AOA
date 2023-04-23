#include <stdio.h>
#include <conio.h>

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    int flag = 0;
    int size = 10;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == key)
        {
            flag = 1;
            printf("The value 5 is found at index : %d", i);
        }
    }
    if (flag == 0)
    {
        printf("The value you are searching is not there in the array");
    }

    return 0;
}