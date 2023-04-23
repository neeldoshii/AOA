#include <stdio.h>
#include <conio.h>

int main()
{
    // object,profit,weight, ratio
    int object = 3; // defined the objects as 3
    float profit[10], weight[10], ratio[10];
    int i = 0;

    printf("Enter the weight and profits corresponding \n");
    for (i = 0; i < object; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    // remove ratio formula ratio = profit/weight

    for (i = 0; i < object; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // sort in descending order according to weight
    // bubble sort
    float temp; // a temp variable
    for (i = 0; i < object; i++)
    {
        for (int j = i + 1; j < object; j++)
        {
            if (ratio[j] > ratio[i])
            {
                // swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // swap profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // capacity of knapsack
    float capacity = 125;
    float x[10]; // for vector as 0/1 knapsack can have in fraction
    float remainingweight = 125;
    float totalProfit = 0;

    for (i = 0; i < object; i++)
    {
        x[i] = 0.0;
    }

    for (i = 0; i < object; i++)
    {
        if (weight[i] < remainingweight)
        {
            remainingweight = remainingweight - weight[i];
            totalProfit += profit[i];
            x[i] = 1.00;
        }
        else
        {
            break;
        }
    }

    if (i < object)
    {
        x[i] = remainingweight / weight[i];
        totalProfit = totalProfit + (x[i] * profit[i]);
    }

    for (i = 0; i < object; i++)
    {
        printf("Vector is %f \n", x[i]);
    }
    printf("Total profit = %f", totalProfit);

    return 0;
}