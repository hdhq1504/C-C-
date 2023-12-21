#include <stdio.h>
#include <math.h>

// Bài 1: Viết hàm tính các biểu thức S(n) theo đệ quy và khử đệ quy (nếu có thể), với n là số nguyên dương nhập từ bàn phím.
// Câu 2.
double sum_S2(int n)
{
    if (n <= 1) return sqrt(2);
    return sqrt(2 + sum_S2(n-1));
}

// Câu 5.
double sum_S5(unsigned int n)
{
    if (n <= 0) return 0;
    return 1.0 / (n * (n + 1) * (n + 2)) + sum_S5(n - 1);
}

// Câu 8.
int sum_S8(unsigned int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += (n * (n + 1)) / 2;
        n--;
    }
    return sum;
}

// Câu 9.
long int factorial(unsigned int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

double sum_S9 (int n)
{
    if (n <= 0) return 0;
    return pow(-1, n) * ((2 * n - 1) + (2 * n)) / (factorial(2 * n)) + sum_S9(n-1);
}

// Câu 10.
double sum_S10 (unsigned int n)
{
    if (n <= 0) return 0;
    return (n * factorial(n + 1)) / ((n + 1) + sqrt(n + 2)) + sum_S10(n-1);
}

// Bài 2: Viết hàm tính m^n với m là số nguyên và n là số nguyên dương nhập từ bàn phím.
int power(int m, int n)
{
    if (n == 0) return 1;
    else if (n == 1) return m;
    return m * power(m, n-1);
}

// Bài 3: Tính UCLN của 2 số nguyên dương a, b
int UCLN (int a, int b)
{
    if (b == 0) return a;
    if (a > b)
        return UCLN(b, a-b);
    else
        return UCLN(a, b-a);
}

// Bài 6: Viết hàm tính biểu thức U(n) sau đây, với n là số nguyên dương nhập từ bàn phím.
int sum_U (int n)
{
    if (n < 6) return n;
    return sum_U(n-5) + sum_U(n-4) + sum_U(n-3) + sum_U(n-2) + sum_U(n-1);
}

int main()
{
    int m, n, a, b;
    printf("Nhap m: "); scanf("%d", &m);
    printf("Nhap n: "); scanf("%d", &n);

    // Bài 1
    printf("S(%d) = %6lf", n, sum_S5(n));
    printf("\nS(%d) = %d", n, sum_S8(n));
    printf("\nS(%d) = %6lf", n, sum_S9(n));
    printf("\nS(%d) = %6lf", n, sum_S10(n));

    // Bài 2
    printf("\n%d^%d = %d", m, n, power(m, n));

    // Bài 3
    printf("\nNhap a: "); scanf("%d", &a);
    printf("Nhap b: "); scanf("%d", &b);
    printf("UCLN(%d, %d) = %d", a, b, UCLN(a, b));

    // Bài 6
    printf("\nU(n) = %d", sum_U(n));

    return 0;
}