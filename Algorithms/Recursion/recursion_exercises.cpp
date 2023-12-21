#include <stdio.h>

// S(n) = 1 + 2 + 3 + ... + n
long int sum_S1(int n)
{
    if (n <= 0) return 0;
    return n + sum_S1(n - 1);
}

// S(n) = 1 + 1/2 + 1/3 + ... + 1/n
float sum_S2(int n)
{
    if (n <= 0) return 0;
    return float(1.0 / n) + sum_S2(n - 1);
}

// S(n) = 1*2 + 2*3 + 3*4 + 4*5 + ... + n(n+1)
int sum_S3(int n)
{
    if (n <= 0) return 0;
    return n * (n + 1) + sum_S3(n - 1);
}

// Tìm phần tử giá trị thứ n của cấp số cộng có số hạng đầu là a, công sai là r
int capSoCong(int n, int a, int r)
{
    if (n == 1) return a;
    return r + capSoCong(n-1, a, r);
}

// Tìm phần tử giá trị thứ n của cấp số nhân có số hạng đầu là a, công bội là q
int capSoNhan(int n, int a, int q)
{
    if (n == 1) return a;
    return q * capSoCong(n-1, a, q);
}

int main()
{
    int n, a, r, q;
    
    printf("Nhap n: "); scanf("%d", &n);
    printf("Nhap a: "); scanf("%d", &a);
    printf("Nhap r, q: "); scanf("%d %d", &r, &q);

    // Bai 1
    printf("\nS(%d) = %d", n, sum_S1(n));
    printf("\nS(%d) = %f", n, sum_S2(n));
    printf("\nS(%d) = %d\n", n, sum_S3(n));

    // Bài 2
    printf("\nCap so cong U(%d) = %d", n, capSoCong(n, a, r));
    
    // Bài 3
    printf("\nCap so nhan U(%d) = %d", n, capSoNhan(n, a, q));

    return 0;
}