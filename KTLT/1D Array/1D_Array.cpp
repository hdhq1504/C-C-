#include <stdio.h>
#include <math.h>

// Bai Tap 1 - P.85
// 1. Dem so phan tu co gia tri la SNT trong mang a[]
int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int count_isPrime(int a[], int n)
{
    int count = 0; 
    int i = 0;
    while (i < n)
    {
        if (isPrime(a[i]))
            count++;
        i++;
    }
    return count;
}

// 2. Xuat cac phan tu ma tung chu so cua no la so le
int check_OddNumber(int n)
{
    while (n > 0)
    {
        if ((n % 10) % 2 == 0)
            return 0;
        n /= 10;
    }
    return 1;
}

void isOddNumber(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (check_OddNumber(a[i]))
            printf("%d ", a[i]);
    }
}

// 4. Kiem tra co toan chan khong
int check_AllEven(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
            return 0;
    }
    return 1;
}

// 5. Kiem tra mang co la day so chan le khong
int check_ChanLeXenKe(int a[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) 
        {
            return 0;
        }
    }
    return 1;
}

// Bai Tap 2 - P.87
// 1. Kiem tra mang co chua toan bo SNT hay khong
int check_AllPrime(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isPrime(a[i]))
            return 0;
    }
    return 1;
}

// 2. Kiem tra mang co doi xung hay khong
int check_DoiXung(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n-i-1])
            return 0;
    }
    return 1;
}

// 3. Kiem tra mang co tang dan/giam dan/khong tang khong giam
int ktraMang(int a[], int n) 
{
    int increasing = 1;
    int decreasing = 1;

    for (int i = 0; i < n - 1; i++) 
    {
        if (a[i] > a[i + 1])
            increasing = 0;
        else if (a[i] < a[i + 1])
            decreasing = 0;
    }

    if (increasing == 1)
        return 1;
    else if (decreasing == 1)
        return 2;
    else
        return 0;
}


int main()
{   
    int a[7] = {2, 3, 5, 7, 9, 11, 13};
    int n = sizeof(a) / sizeof(a[0]);

    if (ktraMang(a, n) == 1)
        printf("Mang tang dan");
    else if (ktraMang(a, n) == 2)
        printf("Mang giam dan");
    else
        printf("Mang khong tang khong giam");

    return 0;
}