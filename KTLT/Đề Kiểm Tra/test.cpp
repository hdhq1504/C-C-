#include <stdio.h>
#include <string.h>
#define MAXCOL 10000

// Câu 1: Cho một mảng một chiều a chứa n số nguyên dương. Viết hàm tìm vị trí của phần tử chia hết cho 3 nhỏ nhất trong mảng

// int timViTri_PTMin_Boi3(int a[], int n)
// {
//     int imin;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] % 3 == 0)
//         {
//             imin = i;
//             break; // Tìm được phần tử đầu tiên là bội của 3
//         }
//     }
//     if (imin == n)
//     {
//         return -1; // Không có phần tử nào là bội của 3
//     }
//     for (int j = imin + 1; j < n; j++)
//     {
//         if (a[j] % 3 == 0 && a[j] < a[imin])
//             imin = j; // Phần tử Bội của 3 mới
//     }
//     return imin; // Phần tử thứ i là phần tử bội của 3 nhỏ nhất
// }

int timViTriDau_Boi3(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == 0)
            return i;
    }
    return -1;
}

int xuatViTri_PTMin_Boi3(int a[], int n)
{
    int min = timViTriDau_Boi3(a, n);
    if (min == -1)
        return min;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 3 == 0 && a[i] < a[min])
            min = i;
    }
    return min;
}

// Câu 2: Cho ma trận vuông a cấp n số nguyên dương. Tính tổng các giá trị là số thịnh vượng nằm trên đường chéo chính và phụ của ma trận
int ktSoThinhVuong(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    if (sum > n)
        return 1;
    return 0;
}

// int sum_soThinhVuong(int a[][MAXCOL], int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == j || i + j == (n - 1))
//             {
//                 if (ktSoThinhVuong(a[i][j]))
//                     sum += a[i][j];
//             }
//         }
//     }
//     return sum;
// }

int sumSoThinhVuong(int a[][MAXCOL], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ktSoThinhVuong(a[i][i]))
            sum += a[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        if (ktSoThinhVuong(a[i][n - i - 1]))
            sum += a[i][n - i - 1];
    }

    if (n % 2 == 1 && ktSoThinhVuong(a[n / 2][n / 2]))
        sum -= a[n / 2][n / 2];

    return sum;
}

// Câu 3. Viết hàm chèn một chuỗi con subStr và vị trí pos của chuỗi cha mainStr đã cho trước
void chenChuoiCon(char mainStr[], const char subStr[], unsigned int pos)
{
    char *kq;                // Cấp phát cho chuỗi kq một con trỏ
    int m = strlen(mainStr); // Chiều dài chuỗi cha
    int n = strlen(subStr);  // Chiều dài chuỗi con
    if (pos < 0 || pos > m)
        return;              // Nếu vị trí cần chèn không nằm trong mainStr thì return
    int i = 0, j = 0, k = 0; // Khởi tạo các biến chạy i, j, k lần lượt cho chuỗi mainStr, subStr, kq
    int mn = m + n;
    kq = new char[mn]; // Khởi tạo chuỗi kq và chiều dài chuỗi kq bằng tổng độ dài 2 chuỗi mainStr, subStr
    while (i < pos)
    {
        kq[k++] = mainStr[i++]; // Sao chép chuỗi mainStr từ vị trí 0 đến pos-1 vào chuỗi kq
    }
    while (j < n)
    {
        kq[k++] = subStr[j++]; // Sao chép chuỗi subStr từ vị trí 0 đến n-1 vào chuỗi kq
    }
    while (i < m)
    {
        kq[k++] = mainStr[i++]; // Sao chép phần còn lại của chuỗi mainStr vào kq
    }
    kq[mn] = '\0';       // Kết thúc chuỗi kq bằng '\0'
    strcpy(mainStr, kq); // Sao chép toàn bộ chuỗi kq vào chuỗi mainStr để có chuỗi mainStr mới sau khi chèn
}

// Câu 4. Xuất ra màn hình những số Fibonacci thuộc đoạn [x, y] với x, y là 2 số nguyên dương
int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

void lietKeFibonacciThuocXY_DQ(unsigned int x, unsigned int y)
{
    if (x > y)
        printf("Khong co so Fibonacci thuoc doan [%d, %d]", x, y);

    int n = 0;
    int value;
    while ((value = fibonacci(++n)) <= y)
    {
        if (value >= x)
            printf("%d ", value);
    }
}

void lietKeFibonacciThuocXY_NonDQ(unsigned int x, unsigned int y)
{
    if (x > y)
        printf("Khong co so Fibonacci thuoc doan [%d, %d]", x, y);

    int f1 = 1, f2 = 1, fn = 1;
    while (fn <= y)
    {
        if (fn >= x)
            printf("%d ", fn);

        f1 = f2;
        f2 = fn;
        fn = f1 + f2;
    }
}

int main()
{
    // int a[7] = {1, 45, 7, 2, 9, 11, 13};
    // int n = sizeof(a) / sizeof(a[0]);
    // printf("Vi tri cua phan tu chia het cho 3 nho nhat: %d\n", xuatViTri_PTMin_Boi3(a, n));

    // int a[][MAXCOL] = {
    //     {1, 2, 3},
    //     {5, 12, 7},
    //     {4, 8, 6}};
    // int n = 3;
    // printf("Tong cac phan tu la so thinh vuong tren duong cheo chinh va phu: %d", sum_soThinhVuong(a, n));

    char mainStr[30] = "Lap Trinh C";
    char subStr[30] = "Ngon Ngu ";
    printf("%d %d\n", strlen(mainStr), strlen(subStr));
    chenChuoiCon(mainStr, subStr, 0);
    printf("%s\n", mainStr);

    // int x = 10, y = 50;
    // lietKeFibonacciThuocXY_DQ(x, y);
    // printf("\n");
    // lietKeFibonacciThuocXY_NonDQ(x, y);

    return 0;
}
