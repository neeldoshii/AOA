#include <stdio.h>


int main()
{
    int n = 6; // no of nodes
    int cost[10][10];
    printf("Enter the adjacency Matrix of graph \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    int visited[10];
    visited[0] = 1;
    int min = 999;
    int ne = 1;
    int i, j;
    
    int mincost = 0;
    while (ne < n)
    {
        min = 999;
        int a = -1, b = -1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        a = i;
                        b = j;
                        min = cost[i][j];
                    }
                }
            }
        }

        if (a != -1 && b != -1)
        {
            visited[b] = 1;
  
            mincost = mincost + min;
            printf("Edge %d : (%d,%d), Cost - %d\n", ne, a, b, min);
                      ne++;
        }
    }

    printf("\nTotal Cost : %d", mincost);
}

// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6
// 0 0 4 2 6 0