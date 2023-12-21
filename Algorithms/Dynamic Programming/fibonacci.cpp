#include <stdio.h>

int basicRecursion(int n)
{
   if (n == 1 || n == 2) return 1;
   return basicRecursion(n - 1) + basicRecursion(n - 2);
}

int memoizeRecursionFib(int n, int cache[])
{
    cache[0] = 0, cache[1] = 1, cache[2] = 1;

    if (cache[n] != 0) return cache[n];

    cache[n] = memoizeRecursionFib(n - 1, cache) + memoizeRecursionFib(n - 2, cache);
    return cache[n];
}

int basicLoopFib(int n, int cache[])
{
    cache[0] = 0, cache[1] = 1, cache[2] = 1;
    if (n == 1 || n == 2) return 1;
    for(int i = 3; i <= n; i++)
    {
        cache[i] = cache[i-1] + cache[i-2];
    }
    return cache[n];
}

int fastLoopFib(int n)
{
    if (n == 1 || n == 2) return 1;
    int first, second = 1;
    for(int i = 3; i <= n; i++)
    {
        second = first + second;
        first = second - first;     
    }
    return second;
}

int main()
{
    int n;
    printf("Nhap so n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("n phai lon hon 0.\n");
        return 1;
    }

    int cache[n + 1]; // Declare an array to store computed values.
    for (int i = 0; i <= n; i++)
    {
        cache[i] = 0; // Initialize an array with the value 0 to indetify values that not have been computed yet.
    }

    printf("Ket qua su dung basicRecursion(%d): %d\n", n, basicRecursion(n));
    printf("Ket qua su dung memoizeRecursionFib(%d): %d\n", n, memoizeRecursionFib(n, cache));
    printf("Ket qua su dung Loop(%d): %d\n", n, basicLoopFib(n, cache));

    return 0;
}
