#include <stdio.h>

int find(int);
int uni(int, int);

// macro

int parent[10] = {0};
int main()
{
    int n = 6; // no of nodes
    int cost[10][10];
    int i, j;
    int mincost = 0;
    printf("Enter an adjacency Matrix \n");
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

    int ne = 1;

    int a = 0, b = 0, min = 999;
    int u = 0, v = 0;

    while (ne < n)
    {
        min = 999;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
        }
        cost[b][a] = cost[a][b] = 999;
    }
    printf("\n\tMinimum cost = %d\n", mincost);
}
int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        parent[i] = j;
        return 1;
    }
    return 0;
}

// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6