#include <stdio.h>
#include <math.h>
#define MAXCOL 10000

// Bai Tap 1 - P.95
// 1. Tinh tong cac phan tu co chu so dau la chu so le
int firstNum(int n)
{
    n = abs(n);
    while (n >= 10)
        n /= 10;
    return n;
}

int sum(int a[][MAXCOL], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (firstNum(a[i][j]) % 2 == 1)
                sum += a[i][j];
        }
    }
    return sum;
}

// 2. Liet ke cac so hoan thien trong ma tran
int soHoanThien(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return (sum == n);
}

void lietKe_soHoanThien(int a[][MAXCOL], int m, int n)
{
    printf("Cac so hoan thien trong ma tran la: ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (soHoanThien(a[i][j]))
                printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}

// 3. Tinh tong cac phan tu > tri tuyet doi cua phan tu lien sau no
int sum_PTLonHonTTDPTKeSau(int a[][MAXCOL], int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i][j] > abs(a[i][j + 1]))
                sum += a[i][j];
        }
    }
    return sum;
}

// 4. Tinh tong gia tri tren dong k cua ma tran
int sum_dongK(int a[][MAXCOL], int n, int k)
{
    int sum = 0;
    for (int j = 0; j < n; j++)
        sum += a[k][j];

    return sum;
}

// 5. Tinh tong cac gia tri nam tren bien cua ma tran
int sum_PTBien(int a[][MAXCOL], int m, int n)
{
    int sum = 0;
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
    //             sum += a[i][j];
    //     }
    // }

    for (int j = 0; j < n; j++)
        sum += a[0][j] + a[m - 1][j];

    for (int i = 1; i < m - 1; i++)
        sum += a[i][0] + a[i][n - 1];

    return sum;
}

// 6. Dem tan suat xuat hien cua 1 gia tri x trong ma tran
int count_frequencyOfX(int a[][MAXCOL], int m, int n, int x)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (a[i][j] == x)
                count++;
        }
    }
    return count;
}

// 7. Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to
int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;

    return 1;
}

void count_ChanLeAmDuongSNT(int a[][MAXCOL], int m, int n)
{
    int count_le = 0;
    int count_chan = 0;
    int count_am = 0;
    int count_duong = 0;
    int count_SNT = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] % 2 == 0)
                count_chan++;
            else if (a[i][j] % 2 != 0)
                count_le++;
            if (a[i][j] < 0)
                count_am++;
            else if (a[i][j] > 0)
                count_duong++;
            if (isPrime(a[i][j]))
                count_SNT++;
        }
    }

    printf("So le: %d\n", count_le);
    printf("So chan: %d\n", count_chan);
    printf("So am: %d\n", count_am);
    printf("So duong: %d\n", count_duong);
    printf("So nguyen to: %d\n", count_SNT);
}

// Bai Tap 2 - P.97
// 1. Liet ke cac cot co tong nho nhat trong ma tran
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

void lietKeCacCotCoTongMin(int a[][MAXCOL], int m, int n)
{
    int jmin = timCotTongMin(a, m, n);
    int vmin = tinhTongCotK(a, m, n, jmin);
    printf("\nTong cot min = %d cua cot: %d", vmin, jmin);
    for (int j = jmin + 1; j < n; j++)
    {
        int vj = tinhTongCotK(a, m, n, j);
        if (vj == vmin)
            printf(", %d", j);
    }
}

// 3. Liet ke chi so cac dong chua toan gia tri chan
bool isEven(int n)
{
    return n % 2 == 0;
}

bool isAllEvenRowK(int a[][MAXCOL], int m, int n, int k)
{
    for (int j = 0; j < n; j++)
    {
        if (!isEven(a[k][j]))
            return false;
    }
    return true;
}

void lietKeCacDongHoanToanChan(int a[][MAXCOL], int m, int n)
{
    printf("\nDanh sach cac dong hoan toan chan: ");
    for (int i = 0; i < m; i++)
    {
        if (isAllEvenRowK(a, m, n, i))
            printf("%d ", i);
    }
}

// 4. Tim gia tri xuat hien nhieu nhat trong ma tran
// B1: Do ma tran ra mang 1 chieu
void makeOneArrayFromMatrix(int a[][MAXCOL], int m, int n, int b[], int &k)
{
    k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            b[k++] = a[i][j];
    }
}

// B2: Sap xep mang 1 chieu tang dan
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void sortOneArrayAscending(int b[], int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (b[i] > b[j])
                swap(b[i], b[j]);
        }
    }
}

// B3: Tao 1 mang 1 chieu cau truc luu tru 1 cap thong tin (value, frequency)
struct TanXuat
{
    int value;
    int count;
};

void taoMangTanXuat(int b[], int k, TanXuat c[], int &nc)
{
    nc = 0;
    int count = 1;
    int i = 0;
    while (i < k)
    {
        if (b[i] == b[i + 1])
            count++;
        else
        {
            c[nc].value = b[i];
            c[nc].count = count;
            nc++;
        }
        i++;
    }
}

// B4: Tim vi tri frequency lon nhat
int viTriPhanTuDauTienXuatHienNhieuNhat(TanXuat c[], int nc)
{
    int imax = 0;
    for (int i = 0; i < nc; i++)
    {
        if (c[i].count > c[imax].count)
            imax = i;
    }
    return imax;
}

// B5: Liet ke all phan tu co frequency lon nhat
void xuatPhanTuDauXuatHienNhieuNhat(TanXuat c[], int nc)
{
    int imax = viTriPhanTuDauTienXuatHienNhieuNhat(c, nc);
    printf("%d ", c[imax].value);
    for (int j = imax + 1; j < nc; j++)
    {
        if (c[j].count == c[imax].count)
            printf("%5d", c[j].value);
    }
    printf(" co so lan xuat hien nhieu nhat la: %d", c[imax].count);
}

int main()
{
    int a[3][MAXCOL] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int m = 3;
    int n = 3;

    int kq = sum_PTBien(a, m, n);
    printf("%d\n", kq);

    return 0;
}