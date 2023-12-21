#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCOL 10000

void nhapMang2C(int a[][MAXCOL], int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Tính tổng tam giác trên, tam giác dưới đường chéo chính
int sumTamGiacTrenDuongCheoChinh(int a[][MAXCOL], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            sum += a[i][j];
    }
    return sum;
}
int sumTamGiacDuoiDuongCheoChinh(int a[][MAXCOL], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            sum += a[i][j];
    }
    return sum;
}

// Tính tổng tam giác trên, tam giác dưới đường chéo phụ
int sumTamGiacTrenDuongCheoPhu(int a[][MAXCOL], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            sum += a[i][j];
    }
    return sum;
}
int sumTamGiacDuoiDuongCheoPhu(int a[][MAXCOL], int n)
{
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= n - i - 1; j--)
            sum += a[i][j];
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][MAXCOL];
    nhapMang2C(a, n);
    int res = sumTamGiacDuoiDuongCheoChinh(a, n);
    printf("%d", res);
    return 0;
}