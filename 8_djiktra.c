#include <stdio.h>
#include <stdlib.h>
void djiktras(int n, int cost[20][50], int s, int dist[10])
{
    int i, v, count = 1, min, visited[10];
    for (i = 1; i <= n; i++)
    {   
        visited[i] = 0;
        dist[i] = cost[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;
    while (count <= n) // count will increase to represent all nodes one by one
    {
        min = 999;
        v=0;
        if (dist[i] < min && visited[i] == 0)
        {
            min = dist[i];
            v = i; // V is next node and i is current node
        }
        visited[v] = 1;
        count++;
        for (i = 1; i <= n; i++)
        {
            if (cost[v][i]!=0 && dist[i] > dist[v] + cost[v][i])
                dist[i] = dist[v] + cost[v][i];
        }
    }
}

int main()
{
    int i, j, s, n, cost[20][20], dist[20];
    printf("enter total no. of Vertex\n");
    scanf("%d", &n);
    printf("Enter cost matrix\n");//left to right(column)
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    printf("Enter the source vertex\n");
    scanf("%d", &s);
    djiktras(n, cost, s, dist);
    printf("Shortest path from %d is :\n",s);
    for (i = 1; i <= n; i++)
    {
        if (s != i)
        {
            printf("%d -> %d = %d \n", s, i, dist[i]);
        }
    }
    return 0;
}