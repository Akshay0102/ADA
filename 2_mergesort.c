#include <stdio.h>

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int A[50], n;

    printf("enter size\n");
    scanf("%d", &n);
    printf("enter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    mergesort(A, 0, n);

    printf("Sorted array is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}