#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int k[20][20];
    for (i = 0; i < n; i++)
    {
        for (w = 0; w < W; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    }
    return k[n][W];
}

int main()
{
    int i, n, val[20], wt[20], W;
    printf("enter number of objects\n");
    scanf("%d", &n);

    printf("enter value and weight of objects :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("enter size of knapsack\n");
    scanf("%d", &W);

    printf("%d is the profit", knapsack(W, wt, val, n));
    return 0;
}