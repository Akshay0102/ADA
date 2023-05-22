#include <stdio.h>

void BinarySearch(int A[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == A[mid])
        {
            printf("The value is on %dth position\n", mid);
            break;
        }
        else if (key > A[mid])
        {
            BinarySearch(A, mid + 1, high, key);
        }
        else
        {
            BinarySearch(A, low, mid-1, key);
        }
    }
}
int main()
{
    int A[50], low, high, key, n, i;
    low = 0;
    high = n - 1;
    printf("enter the total no. of elements in the array\n");
    scanf("%d", &n);
    printf("enter the values in sorted manner\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("enter the value to search\n");
    scanf("%d", &key);
    BinarySearch(A, low, high, key);
    return 0;
}
