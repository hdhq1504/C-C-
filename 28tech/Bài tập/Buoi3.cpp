#include <stdio.h>
#include <math.h>

// Bai 1. S = 1 + 2 + 3 + ... + n
void sumS1(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("%d", sum);
}

// Bai 2. S = 1^2 + 2^2 + 3^2 + 4^2 + ... + n^2
void sumS2(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += pow(i, 2);
    printf("%d", sum);
}

// Bai 3. Tong cac so nguyen khong vuot n, chia het cho 3
void sumChiaHet3(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
            sum += i;
    }
    printf("%d", sum);
}

// Bai 4. Tinh S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n (lay 3 so sau dau thap phan)
void sumPhanSo1(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    float sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (float)1 / n;
    printf("%.3f", sum);
}

// Bai 5. Tinh S = 1/2 + 1/4 + 1/6 + 1/8 + ... + 1/(2n) (lay 3 so sau dau thap phan)
void sumPhanSo2(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    float sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (float)1 / (2 * n);
    printf("%.2f", sum);
}

// Bai 6. S = -1 + 2 - 3 + 4 - 5 + ... + (-1)^n*n
void sumS6(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (i % 2 != 0)
            sum -= i;
        else
            sum += i;
    printf("%d", sum);
}

// Bai 7. Tinh S = 2 + 4 + 6 + 8 + ...... + 2 * n
void sumS7(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += 2 * i;
    printf("%d", sum);
}

// Bai 8. Tinh S = 1 + 3 + 5 + 7 + ..... + 2 * n - 1
void sumS8(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (2 * i) - 1;
    printf("%d", sum);
}

// Bai 9. Tinh S = 1^3 + 2^3 + 3^3 + 4^3 + ...... + n^3
void sumS9(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += pow(i, 3);
    printf("%d", sum);
}

// Bai 10. Tinh n! = 1.2.3. .... .n
void sumS10(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial *= i;
    printf("%d", factorial);
}

// Bai 11. Nhap x, y nguyen khong am, tinh x^y
void power(int x, int y)
{
    printf("Nhap x, y: ");
    scanf("%d %d", &x, &y);
    int result = 1;
    for (int i = 1; i <= y; i++)
        result *= x;
    printf("%d", result);
}

// Bai 12. Dem so luong chu so cua n
void demChuSoN(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    printf("%d", count);
}

// Bai 13. Tinh tong cac chu so cua n
void sumChuSoN(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    while (n > 0)
    {
        int mod = n % 10;
        sum += mod;
        n /= 10;
    }
    printf("%d", sum);
}

// Bai 14. Tinh tong cac chu so chan va tong cac chu so le
void sumChanLe(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int sumEven = 0, sumOdd = 0;
    while (n > 0)
    {
        int mod = n % 10;
        if (mod % 2 == 0)
            sumEven += mod;
        else
            sumOdd += mod;
        n /= 10;
    }
    printf("%d %d", sumEven, sumOdd);
}

// Bai 15. In ra so luong chu so chan le cua n
void demChanLe(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int countOdd = 0, countEven = 0;
    while (n > 0)
    {
        int mod = n % 10;
        if (mod % 2 == 0)
            countEven++;
        else
            countOdd++;
        n /= 10;
    }
    printf("%d %d", countEven, countOdd);
}

// Bai 16. Dem so luong chu so cua n la SNT
int soNguyenTo(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void demSNT(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int count = 0;
    while (n > 0)
    {
        int mod = n % 10;
        if (soNguyenTo(mod))
            count++;
        n /= 10;
    }
    printf("%d", count);
}

// Bai 17. Kiem tra so dep (so luong chu so chan == chu so le)
void ktraSoDep(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    int countOdd = 0, countEven = 0;
    while (n > 0)
    {
        int mod = n % 10;
        if (mod % 2 == 0)
            countEven++;
        else
            countOdd++;
        n /= 10;
    }
    if (countEven == countOdd)
        printf("YES");
    else
        printf("NO");
}

// Bai 18. Bieu dien n duoi dang tong cua cac SNT => so luong so hang trong tong la max
void timTongSNTLonNhat(int n)
{
    printf("Nhap n: ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("%d\n", n / 2);
        for (int i = 1; i <= n / 2; i++)
            printf("2 ");
    }
    else
    {
        int result = n - 3;
        printf("%d\n", (result / 2) + 1);
        for (int i = 1; i <= result / 2; i++)
            printf("2 ");
        printf("3 ");
    }
}

// Bai 19. In n chu so chia het cho t

// Bai 20. Miskha & Chris
void MishkaChris(int m, int c, int n)
{
    printf("Nhap so vong choi : ");
    scanf("%d", &n);
    int mishkaWin = 0, chrisWin = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri xuc xac cua Miskha & Chris: ");
        scanf("%d %d", &m, &c);

        if (m > c)
            mishkaWin++;
        if (c > m)
            chrisWin++;
    }

    if (mishkaWin > chrisWin)
        printf("Mishka");
    else if (mishkaWin < chrisWin)
        printf("Chris");
    else
        printf("Friendship is magic!^^");
}

// Bai 21.
void DayOff(int n)
{
    printf("Nhap so ngay trong nam: ");
    scanf("%d", &n);
    int min = 0, max = 0;
    if (n % 7 == 0)
    {
        min = n / 7 * 2;
        max = n / 7 * 2;
    }
    else
    {
        if (n % 7 == 1)
        {
            max = n / 7 * 2 + 1;
            min = n / 7 * 2;
        }
        else if (n % 7 > 1 && n % 7 <= 5)
        {
            max = n / 7 * 2 + 2;
            min = n / 7 * 2;
        }
        else
        {
            max = n / 7 * 2 + 2;
            min = n / 7 * 2 + 1;
        }
    }
    printf("%d %d\n", min, max);
}

// Bai 23.
int factorial (int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
void chiaTao1(int n, int m)
{
    scanf("%d %d", &n, &m);
    int k = n - m;
    int toHop = factorial(n - 1) / (factorial(k) * factorial((n - 1) - k));
    printf("%d", toHop);
}

// Bai 24
void chiaTao2(int n, int m)
{
    scanf("%d %d", &n, &m);
    int k = n - 1;
    int toHop = factorial(m + n - 1) / (factorial(k) * factorial((m + n - 1) - k));
    printf("%d", toHop);
}

// Bai 25
void demSo0(long long n)
{
    printf("Nhap n: ");
    scanf("%lld", &n);
    long long count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    printf("%d", count);
}

int main()
{
    int n;
    sumChuSoN(n);

    return 0;
}