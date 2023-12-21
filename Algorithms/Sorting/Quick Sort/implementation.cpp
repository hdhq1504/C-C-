#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return (i+1);
}

void QuickSort (int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

int main()
{
    int a[] = {3, 2, 0, 8, 7, 5, 9, 1, 4, 6};
    int n = sizeof(a)/sizeof(a[0]);

    QuickSort(a, 0, n-1);
    printf("Sorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}