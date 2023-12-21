#include <stdio.h>
#include <math.h>

// Bai 1.
void doDai12Canh_HHCN(int a, int b, int c)
{
    scanf("%d %d %d", &a, &b, &c);
    if (a > 10000 && b > 10000 && c > 10000)
        return;
    else
    {
        int ChieuDai = sqrt((a * b) / c); // Tính chiều dài
        int ChieuRong = a / ChieuDai;     // Tính chiều rộng
        int ChieuCao = c / ChieuDai;      // Tính chiều cao
        int sum = 4 * (ChieuDai + ChieuRong + ChieuCao);
        printf("%d", sum);
    }
}

// Bai 2.
void maxDomino(int m, int n)
{
    scanf("%d %d", &m, &n);
    int result = (m * n) / 2;
    printf("%d", result);
}

// Bai 3.
void numberOfIce(int n, int m, int a)
{
    scanf("%d %d %d", &n, &m, &a);

    int numLength, numWidth;
    if (n % a == 0)
        numLength = n / a;
    else
        numLength = (n / a) + 1;

    if (m % a == 0)
        numWidth = m / a;
    else
        numWidth = (m / a) + 1;

    int res = numLength * numWidth;
    printf("%d", res);
}

// Bai 4.
void frog(int a, int b, int k)
{
    scanf("%d %d %d", &a, &b, &k);
    int pos = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i % 2 == 1)
            pos += a;
        else
            pos -= b;
    }
    printf("%d", pos);
}

// Bai 5.
void drazil(int a, int b, int s)
{
    scanf("%d %d %d", &a, &b, &s);
    int khoangCach = abs(a) + abs(b);
    if (khoangCach > s || (s - khoangCach) % 2 == 1)
        printf("NO");
    else
        printf("YES");
}

// Bai 6.
void muaNuoc(long long n, int a, int b)
{
    scanf("%lld %d %d", &n, &a, &b);

    // Trường hợp 1: Mua tất cả nước từ chai 2 lít
    // Nhân số lượng chai 2 lít cần mua với giá của chai 2 lít
    long long case1 = (n / 2) * (2 * a > b ? 2 * a : b);
    if (n % 2 == 1)
        case1 += a;

    // Trường hợp 2: Mua tất cả nước từ chai 1 lít
    // Nhân số lượng chai 1 lít cần mua với giá của chai 1 lít
    long long case2 = n * a;

    long long result = (case1 < case2 ? case1 : case2);
    printf("%lld", result);
}

// Bai 7.
void numOfCoinsEqualToS(int n, int S)
{
    scanf("%d %d", &n, &S);
    int count = 0;
    while (S > 0)
    {
        count += S / n; // Số lượng đồng xu có giá trị n cần thêm vào tổng
        S %= n;         // Cập nhật tổng S sau khi thêm đồng xu có giá trị n
        n--;            // Giảm giá trị của đồng xu n xuống 1 đơn vị để thử với đồng xu có giá trị nhỏ hơn
    }
    printf("%d ", count);
}

// Bai 8.
void minBill(int n)
{
    scanf("%d", &n);
    int min = 0;
    int menhGia[] = {100, 20, 10, 5, 1};
    int size = sizeof(menhGia) / sizeof(menhGia[0]);
    for (int i = 0; i < size; i++)
    {
        if (n >= menhGia[i])
        {
            min += n / menhGia[i];
            n %= menhGia[i];
        }
        else
            continue;
    }
    printf("%d", min);
}

// Bai 9.
void dreamMoon(int n, int m)
{
    scanf("%d %d", &n, &m);
    int result = 0;
    if (m > n)
        printf("-1");
    else
    {
        if (n % 2 == 0)
            result = n / 2 + 1;
        else
        {
            result = n / 2;
            while (result % m > 0)
                result++;
        }
    }
    printf("%d", result);
}

int main()
{
    // int a, b, c;
    // doDai12Canh_HHCN(a, b, c);

    // int m, n;
    // maxDomino(m, n);

    // int n, m, a;
    // numberOfIce(n, m, a);

    // int a, b, k;
    // frog(a, b, k);

    // int a, b, s;
    // drazil(a, b, s);

    // int n, a, b;
    // muaNuoc(n, a, b);

    // int n, S;
    // numOfCoinsEqualToS(n, S);

    // int n;
    // minBill(n);

    int n, m;
    dreamMoon(n, m);

    return 0;
}