#include <stdio.h>

int main()
{
    int n;            // number of nodes
    int cost[10][10]; // cost adjacency matrix
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999; // set 0 cost to a high value to represent no edge
            }
        }
    }

    int visited[10] = {0};
    visited[0] = 1;  // start from node 0
    int ne = 1;      // number of visited nodes
    int mincost = 0; // total cost of MST

    while (ne < n)
    {
        int min = 999;
        int a = -1, b = -1; // nodes corresponding to the minimum edge
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            { // only consider visited nodes
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    { // find the minimum edge to an unvisited node
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1)
        { // if a minimum edge was found
            printf("Edge %d: (%d, %d) cost %d\n", ne, a, b, min);
            visited[b] = 1; // mark the new node as visited
            ne++;
            mincost += min; // add the cost of the edge to the total cost
        }
    }
    printf("Minimum cost: %d\n", mincost); // print the total cost of the MST
    return 0;
}

// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6
// 0 0 4 2 6 0