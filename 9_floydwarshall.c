#include <stdio.h>

int a[10][10], d[10][10], n;
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd()
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
void main()
{
    int i, j;
    printf("enter no of vertices\n");
    scanf("%d", &n);
    printf("enter the cost matrix:\n");//in place of infinity enter any large no. like 9999 999 etc
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j];
        }
    }
    floyd(); // Floyd warshall function called
    printf("the final distance is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d", d[i][j]);
        }
        printf("\n");
    }
}