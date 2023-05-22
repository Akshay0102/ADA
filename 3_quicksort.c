#include <stdio.h>


void printarray( int*a , int n )
{
 for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    while (i < j);
    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}

void quicksort(int a[], int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1);
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{
    int a[] = {35, 5, 49, 1, 2};
    int n = 5;
    printarray(a,n);
    quicksort(a, 0, n - 1);
    printarray(a,n);
    return 0;
   
}