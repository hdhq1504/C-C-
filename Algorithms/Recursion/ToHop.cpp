#include <stdio.h>

int ToHop_DeQuy(int n, int k)
{
    if (k == 1) return n;
    return ToHop_DeQuy(n, k - 1) * (double)(n - k + 1) / k;
}

int ToHop_NonDeQuy(int n, int k)
{
    int result = 1;
    for (int i = 1; i <= k; i++, n--)
    {
        result *= (double)n / i;
    }
    return result;
}

int timMax(int a[], int n)
{
    if (n == 1) return a[0];
    int max = timMax(a, n - 1);
    if (a[n - 1] > max) return a[n - 1];
    return max;
}

int main()
{
    // int a[5] = {0, 4, 2, 5, 3};
    // int n = sizeof(a) / sizeof(a[0]);
    // printf("Max: %d", timMax(a, n));
    
    int n = 10, k = 6;
    printf("De quy: %d\n", ToHop_DeQuy(n, k));
    printf("Khu de quy: %d", ToHop_NonDeQuy(n, k));
    
    return 0;
}