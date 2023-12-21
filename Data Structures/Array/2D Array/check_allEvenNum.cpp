#include <stdio.h>
#include <math.h>
#define MAXCOL 1000000

int tinhTongCotK(int a[][MAXCOL], int m, int n, int k)
{
    int tong = 0;
    for (int i = 0; i < m; i++)
        tong += a[i][k];
    return tong;
}

int timCotTongMin(int a[][MAXCOL], int m, int n)
{
    int jmin = 0;
    int vmin = tinhTongCotK(a, m, n, jmin);
    for (int j = 1; j < n; j++)
    {
        int vj = tinhTongCotK(a, m, n, j);
        if (vj < vmin)
        {
            jmin = j;
            vmin = vj;
        }
    }
    return jmin;
}

void lietKeCacDongCoTongMin(int a[][MAXCOL], int m, int n)
{
    int jmin = timCotTongMin(a, m, n);
    int vmin = tinhTongCotK(a, m, n, jmin);
    printf("\nTong cot min = %d cua cot: %d", vmin, jmin);
    for(int j = jmin + 1; j < n; j++)
    {
        int vj = tinhTongCotK(a, m, n, j);
        if(vj == vmin)
            printf(", %d", j);
    }
}
