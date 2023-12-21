#include <stdio.h>
#include <math.h>

void minSumAbsPair(int arr[], int n)
{
    if (n < 2)
    {
        printf("Invalid input");
        return;
    }

    int min_l = 0;
    int min_r = 1;
    int min_sum = arr[0] + arr[1];

    for(int l = 0; l < n-1; l++)
    {
        for(int r = l+1; r < n; r++)
        {
            int sum = arr[l] + arr[r];
            if(abs(min_sum) > abs(sum))
            {
                min_sum = sum;
                min_l = l;
                min_r = r;
            } 
        }
    }

    printf("The two elements closest to zero are %d and %d", arr[min_l], arr[min_r]);
}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);
    minSumAbsPair(arr, n);
    getchar();
    return 0;
}