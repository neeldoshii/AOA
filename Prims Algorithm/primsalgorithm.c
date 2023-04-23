/* ----------------------------------------- Neel Doshi ----------------------------------------- */

#include <stdio.h>
#include <conio.h>

int main()
{
    int n;            // no of nodes
    int cost[10][10]; // cost of adjacency matrix
    printf("Enter the no of nodes");
    scanf("%d", &n);

    printf("Enter the adjancency matrix : \n");
    int i, j;
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

    int visited[10] = {0};
    visited[1] = 1; // marking the 1st node as visited
    int ne = 1;     // no of visited nodes
    int min = 999;
    int a, b, u, v;
    int mincost = 0; // total cost of MST
    while (ne < n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        u = a = i;
                        v = b = j;
                    }
                }
            }
            if (visited[u] == 0 || visited[v] == 0) // either U or V is not visted
            {
                mincost += min;
                printf("\n Edge %d : (%d %d) cost %d", ne, u, v, min);
                ne++;
                visited[b] = 1; // to not make a loop mark it as visited
            }
            cost[a][b] = cost[b][a] = 999; // not make a loop so make sure by putting 999 which will not detect in min
        }
    }

    printf("\n Minimum Cost : %d", mincost);
}