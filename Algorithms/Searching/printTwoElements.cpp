#include <stdio.h>
#include <stdlib.h>

// void printTwoElements(int a[], int n)
// {
//     int temp[n] = {};

//     int repeat_number = -1;
//     int miss_number = -1;

//     for (int i = 0; i < n; i++)
//     {
//         temp[a[i] - 1]++;
//         if (temp[a[i] - 1] > 1)
//         {
//             repeat_number = a[i];
//             break;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (temp[i] == 0)
//         {
//             miss_number = i + 1;
//             break;
//         }
//     }
//     printf("\nThe repeating number is: %d", repeat_number);
//     printf("\nThe missing number is: %d", miss_number);
// }

void printTwoElements(int arr[], int size)
{
    printf("\nThe repeating element is ");

    for (int i = 0; i < size; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            printf(" %d ", abs(arr[i]));
    }

    printf("\nand the missing element is ");
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            printf("%d", i + 1);
    }
}

// Driver code
int main()
{
    int arr[] = {3, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
    getchar();
}
