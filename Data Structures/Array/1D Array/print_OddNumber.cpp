#include <stdio.h>

bool check_OddNumber(int n)
{
    while (n != 0)
    {
        if ((n % 10) % 2 == 0)
            return false;
        n /= 10;
    }
    return true;
}

void print_OddNumber(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (check_OddNumber(a[i]))
        {
            printf("%d ", a[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    print_OddNumber(a, n);
    return 0;
}