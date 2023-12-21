#include <stdio.h>

// Naive Approach
int firstRepeatingElement(int a[], int n)
{
    // The outer loop picks an element one by one
    for(int i = 0; i < n; i++)
    {
        // The inner loop checks whether the element is repeated or not
        for(int j = i+1; j < n; i++)
        {
            // If a repeating element is found, return its index
            if(a[i] == a[j])
            {
                return i; 
            }
        }
    }
    // If no repeating element is found, return -1
    return -1;
}

#include <stdio.h>

void duplicate(int a[], int temp[], int n)
{
    for(int i = 0; i < n; i++)
    {
        temp[i] = a[i];
    }
}

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int a_val = a[i];
                a[i] = a[j];
                a[j] = a_val;
            }
        }
    }
}

int binarySearch(int a[], int l, int r, int x)
{
    if(r >= l)
    {
        int mid = l + (r-l)/2;
        if(a[mid] == x)
            return mid;
        else if(a[mid] > x)
            return binarySearch(a, l, mid-1, x); 
        else
            return binarySearch(a, mid+1, r, x);
    }
    return -1;
}

int countOccurrences(int temp[], int n, int x)
{
    int index = binarySearch(temp, 0, n-1, x);
    
    // If element is not present
    if(index == -1)
        return 0;

    int count = 1;
    
    // Count elements on left side
    int left = index -1;
    while(left >= 0 && temp[left] == x)
        count++, left--;
    
    // Count elements on right side
    int right = index + 1;
    while(right < n && temp[right] == x)
        count++, right++;

    return count;
}

int firstRepeatingElement(int a[], int n)
{
    // Initialize a temp[] array
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    
    // Duplicate and sort temp[]
    duplicate(a, temp, n);
    bubbleSort(temp, n);

    // Count the occurrences in temp[], if the count is bigger than 1, 
    // return the index in the original array a[]
    for(int i = 0; i < n; i++)
    {
        int count = countOccurrences(temp, n, a[i]);
        if(count > 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int index = firstRepeatingElement(a, n);

    // Checking if any repeating element is found or not
    if (index == -1)
    {
        printf("\nNo repeating element found");
    }
    else
    {
        // Printing the first repeating element
        printf("\nFirst repeating element is: %d", a[index]);
    }
    getchar();
    return 0;
}
