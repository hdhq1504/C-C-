#include <stdio.h>
#include <math.h>

bool isPrime(int n)
{
    if (n < 2)
        return false;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int count_isPrime(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n; 
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int result = count_isPrime(a, n);
    printf("%d", result);
    return 0;
}