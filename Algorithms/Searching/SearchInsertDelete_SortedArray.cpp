// C program to implement insert operation in an sorted array.
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}

int insertSorted(int arr[], int n, int key, int capacity)
{
    // Cannot insert more elements if n is already
    // more than or equal to capacity
    if (n >= capacity)
        return n;
    int i;
    for (i = n - 1; (i >= 0 && arr[i] > key); i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = key;

    return (n + 1);
}

int deleteElement(int arr[], int n, int key)
{
    // Find position of element to be deleted
    int pos = binarySearch(arr, 0, n - 1, key);

    if (pos == -1)
    {
        printf("Element is not found");
        return 0;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

void input(int arr[], int &n, int key)
{
    printf("\nBefore Insert %d:\n", key);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

/* Driver code */
int main()
{
    int arr[20] = {12, 16, 20, 40, 50, 70};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    int n = 6;
    int key = 26;

    //Function call
    input(arr, n, key);

    // Search Element
    printf("\n\nIndex: %d", binarySearch(arr, 0, n - 1, key));

    // Insert Element
    n = insertSorted(arr, n, key, capacity);
    printf("\n\nAfter Insert %d:\n", key);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Delete Element
    n = deleteElement(arr, n, key);
    printf("\n\nAfter Delete %d\n", key);
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);

    getchar();
}
