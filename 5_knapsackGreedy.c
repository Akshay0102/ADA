#include <stdio.h>

void knapsack(int num, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < num; i++)
    {
        x[i] = 0.0;   
    }

    for (i = 0; i < num; i++)
    {
        if (weight[i] > u)
            break;
        else
            x[i] = 1.0;
        tp = tp + profit[i];
        u = u - weight[i];
    }
    if (i < num)
    {
        x[i] = u / weight[i];
    }
    tp = tp + (x[i] * profit[i]);
    printf("The result vector is:\n");
    for (i = 0; i < num; i++)
    {
        printf("%f ", x[i]);
    }
    printf("Max profit is: %f ", tp);
}

int main()
{
    float weight[20], profit[20], ratio[20], capacity, temp;
    int num, i, j; // num=no of obj

    printf("enter the no of objects\n");
    scanf("%d", &num);

    printf("enter the weights and profits of each object\n");
    for (i = 0; i < num; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }
    printf("enter the total capacity of knapsack\n");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    knapsack(num, weight, profit, capacity);
    return 0;
}