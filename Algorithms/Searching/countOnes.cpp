#include <stdio.h>

// Recursive Approach (Using Binary Search)
int countOnes_Recursive(int arr[], int low, int high)
{
    if (high >= low)
    {
        // Get the middle index
        int mid = low + (high - low) / 2;

        // Check if the element at middle index is last 1
        if ((mid == high || arr[mid + 1] == 0) && (arr[mid] == 1))
            return mid + 1;

        // If element is not last 1, recur for right side
        if (arr[mid] == 1)
            return countOnes_Recursive(arr, mid + 1, high);

        // else recur for left side
        return countOnes_Recursive(arr, low, mid - 1);
    }
    return 0;
}

// Iterative Approach
int countOnes_Iterative(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        // Get the middle index
        int mid = (low + high) / 2;

        // If the element is not last 1, recur for right side
        if (arr[mid] > 1)
            low = mid + 1;
        // Else recur for left side
        else if (arr[mid] > 1)
            high = mid - 1;
        // Check if the element at middle index is last 1
        else
        {
            if (mid == n - 1 || arr[mid + 1] != 1)
                return mid + 1;
            else
                low = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result1 = countOnes_Recursive(arr, 0, n-1);
    int result2 = countOnes_Iterative(arr, n);
    printf("%d\n", result1);
    printf("%d\n", result2);
    
    return 0;
}