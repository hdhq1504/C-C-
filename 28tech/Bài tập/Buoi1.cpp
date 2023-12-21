#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

// Bai 1.
void divide_mod(int a, int b)
{
    printf("Nhap a, b: "); scanf("%d %d", &a, &b);
    int div = a / b;
    int mod = a % b;
    printf("%d %d", div, mod);
}

// Bai 2.
void bieuThuc1(int x)
{
    printf("Nhap x: "); scanf("%d", &x);
    if (x > 1000000) return;
    int result = pow(x, 3) + 3 * pow(x, 2) + x + 1;
    printf("%d", result);
}

// Bai 3.
void bieuThuc2(int a, int b, int c)
{
    printf("Nhap a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    int result = a * (b + c) + b * (a + c);
    printf("%d", result);
}

// Bai 4.
void tongHieuTichThuong(int a, int b)
{
    printf("Nhap a, b: "); scanf("%d %d", &a, &b);
    int sum = a + b;
    int sub = a - b;
    long long mul = (long long)a * b;
    float div = float(a) / b;
    printf("%d %d %lld %.2f", sum, sub, mul, div);
}

// Bai 5.
void chuVi_dienTich(int r)
{
    printf("Nhap ban kinh r: ");
    scanf("%d", &r);
    float chuVi = r * 2 * pi;
    float s = pow(r, 2) * pi;
    printf("%.2f %.2f", chuVi, s);
}

// Bai 6.
void eulcid(int x1, int x2, int y1, int y2)
{
    printf("Nhap x1, y1, x2, y2: "); 
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    float result = sqrt(pow(y1 - x1, 2) + pow(y2 - x2, 2));
    printf("%.2f", result);
}

// Bai 7.
void celsiusToF(int C)
{
    printf("Nhap do C: "); scanf("%d", &C);
    float F = (C * (float)9 / 5) + 32;
    printf("%.2f", F);
}

// Bai 8.
void sum1(int n)
{
    printf("Nhap n: "); scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    printf("%lld", sum);
}

// Bai 9.
void sum2(int n)
{
    printf("Nhap n: "); scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += pow(i, 2);
    }
    printf("%lld", sum);
}

// Bai 10.
void sum3(int n)
{
    printf("Nhap n: "); scanf("%d", &n);
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (float)1 / (i * (i + 1));
    }
    printf("%.2f", sum);
}

// Bai 11.
void sum4(int n)
{
    printf("Nhap n: "); scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 2 * i;
    }
    printf("%lld", sum);
}

// Bai 12.
void sum5(long long n) 
{
    printf("Nhap n: "); scanf("%lld", &n);
    long long sum = 0;
    for (long long i = 1; i <= n; i++) 
    {
        if (i % 2 == 0) 
            sum += i;
        else 
            sum -= i;
    }
    printf("%lld", sum);
}

// Bai 13.
void chiaHetLonNhat(int a, int b)
{
    printf("Nhap a, b: "); 
    scanf("%d %d", &a, &b);
    int result = (a / b) * b;
    printf("%d", result); 
}

// Bai 14.
void chiahetNhoNhat(int a, int b)
{
    printf("Nhap a, b: "); 
    scanf("%d %d", &a, &b);
    int mod = a % b;
    int result = a - mod + b;
    if (mod == 0)
        printf("%d", a);
    else
        printf("%d", result);
}

// Bai 15.
void chiaHet3va5(int n)
{
    printf("Nhap n: "); scanf("%d", &n);
    if (n % 3 == 0 && n % 5 == 0)
        printf("1");
    else
        printf("0");    
}

// Bai 16.
void ktraNamNhuan(int n)
{
    printf("Nhap nam: "); 
    scanf("%d", &n);
    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
        printf("YES");
    else if (n <= 0)
        printf("INVALID");
    else
        printf("NO");
}

// Bai 17.
void numbersOfDay(int t, int n)
{
    printf("Nhap thang, nam: ");
    scanf("%d %d", &t, &n);

    if (t > 12 || t < 1 || n < 0)
        printf("INVALID");
    else
    {
        switch(t)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                printf("31");
                break;
            case 4: case 6: case 9: case 11:
                printf("30");
                break;
            case 2:
                if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
                    printf("29");
                else
                    printf("28");
                break;
        }
    }
}

// Bai 18.
void ktraInThuong(char ch)
{
    printf("Nhap ki tu can kiem tra: ");
    fflush(stdin); scanf("%c", &ch);
    if (ch >= 'a' && ch <= 'z') 
        printf("YES");
    else 
        printf("NO");
}

// Bai 19.
void ktraInHoa(char ch)
{
    printf("Nhap ki tu can kiem tra: ");
    fflush(stdin); scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') 
        printf("YES");
    else 
        printf("NO");
}

// Bai 20.
void ktraChuCai(char ch)
{
    printf("Nhap ki tu can kiem tra: ");
    fflush(stdin); scanf("%c", &ch);
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("YES");
    else
        printf("NO");
}

// Bai 21.
void ktraChuSo(char ch)
{
    printf("Nhap ki tu can kiem tra: ");
    fflush(stdin); scanf("%c", &ch);
    if (ch >= 48 && ch <= 57)
        printf("YES");
    else
        printf("NO");
}

// Bai 22.
void hoaThuong(char ch)
{
    printf("Nhap ki tu can chuyen: ");
    fflush(stdin); scanf("%c", &ch);
    if ((ch >= 'A' && ch <= 'Z'))
    {
        ch += 32;
        printf("%c", ch);
    }
    else
        printf("%c", ch);
}

// Bai 23.
void thuongHoa(char ch)
{
    printf("Nhap ki tu can chuyen: ");
    fflush(stdin); scanf("%c", &ch);
    if ((ch >= 'a' && ch <= 'z'))
    {
        ch -= 32;
        printf("%c", ch);
    }
    else
        printf("%c", ch);
}

// Bai 24.
void chuKeTiep(char ch)
{
    printf("Nhap ki tu can chuyen: ");
    fflush(stdin); scanf("%c", &ch);
    if ((ch >= 'A' && ch < 'Z'))
    {
        ch += 33;
        printf("%c", ch);
    }
    else if((ch == 'Z') || (ch == 'z'))
        printf("a");
    else if ((ch >= 'a' && ch < 'z'))
    {
        ch += 1;
        printf("%c", ch);
    }
    else
        printf("INVALID");
}

// Bai 25.
void validTriangle(int a, int b, int c)
{
    printf("Nhap a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a > 0 && b > 0 && c > 0)
    {
        if ((a + b) > c && (b + c) > a && (a + c) > b)
            printf("YES");
        else
            printf("NO");
    }
    else
        printf("NO");
}

// Bai 26.
void ktraTamGiac(int a, int b, int c) 
{
    printf("Nhap a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    if ((a + b > c) && (b + c > a) && (c + a > b))
    {
        if (a == b && b == c)
            printf("1");
        else if (a == b || a == c || c == b)
            printf("2");
        else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a))
            printf("3");
        else
            printf("4");
    }
    else
        printf("INVALID");
}

// Bai 27.
void yearWeekDay(int n)
{
    printf("Nhap so ngay: "); scanf("%d", &n);
    int year = n / 365;
    int week = (n % 365) / 7;
    int day = (n % 365) % 7;
    printf("%d %d %d", year, week, day);
}

void clearScreen()
{
    printf("\n");
    system("pause");
    system("cls");
}

void menu()
{
    printf("\n========================== MENU ==========================\n");
    printf("| 1. Tinh phan nguyen, phan du                           |\n");
    printf("| 2. Tinh gia tri bieu thuc A(x) = x^3 + 3x^2 + x + 1    |\n");
    printf("| 3. Tinh S = a*(b+c) + b*(a+c)                          |\n");
    printf("| 4. Tinh tong, hieu, tich, thuong cua 2 so              |\n");
    printf("| 5. Tinh chu vi, dien tich hinh tron                    |\n");
    printf("| 6. Tinh khoang cach Euclid giua 2 diem trong Oxy       |\n");
    printf("| 7. Chuyen don vi do nhiet do C sang F                  |\n");
    printf("| 8. Tinh tong 1                                         |\n");
    printf("| 9. Tinh tong 2                                         |\n");
    printf("| 10. Tinh tong 3                                        |\n");
    printf("| 11. Tinh tong 4                                        |\n");
    printf("| 12. Tinh tong 5                                        |\n");
    printf("| 13. Tim so chia het lon nhat                           |\n");
    printf("| 14. Tim so chia het nho nhat                           |\n");
    printf("| 15. So chia het cho 3 va 5                             |\n");
    printf("| 16. Kiem tra nam nhuan                                 |\n");
    printf("| 17. In ra so ngay cua thang                            |\n");
    printf("| 18. Kiem tra chu in thuong                             |\n");
    printf("| 19. Kiem tra chu in hoa                                |\n");
    printf("| 20. Kiem tra chu cai                                   |\n");
    printf("| 21. Kiem tra chu so                                    |\n");
    printf("| 22. Chuyen ki tu hoa thanh thuong                      |\n");
    printf("| 23. Chuyen ki tu thuong thanh hoa                      |\n");
    printf("| 24. Chu cai ke tiep                                    |\n");
    printf("| 25. Tam giac hop le                                    |\n");
    printf("| 26. Kiem tra tam giac                                  |\n");
    printf("| 27. Chuyen sang nam, tuan, ngay                        |\n");
    printf("==========================================================\n");
}

int main()
{
    int chon; 
    int a, b, c, n, t, r, x, x1, x2, y1, y2, C;
    char ch;
    do
    {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            divide_mod(a, b);
            clearScreen();
            break;
        case 2:
            bieuThuc1(x);
            clearScreen();
            break;
        case 3:
            bieuThuc2(a, b, c);
            clearScreen();
            break;
        case 4:
            tongHieuTichThuong(a, b);
            clearScreen();
            break;
        case 5:
            chuVi_dienTich(r);
            clearScreen();
            break;
        case 6:
            eulcid(x1, y1, x2, y2);
            clearScreen();
            break;
        case 7:
            celsiusToF(C);
            clearScreen();
            break;
        case 8:
            sum1(n);
            clearScreen();
            break;
        case 9:
            sum2(n);
            clearScreen();
            break;
        case 10:
            sum3(n);
            clearScreen();
            break;
        case 11:
            sum4(n);
            clearScreen();
            break;
        case 12:
            sum5(n);
            clearScreen();
            break;
        case 13:
            chiaHetLonNhat(a, b);
            clearScreen();
            break;
        case 14:
            chiahetNhoNhat(a, b);
            clearScreen();
            break;
        case 15:
            chiaHet3va5(n);
            clearScreen();
        case 16:
            ktraNamNhuan(n);
            clearScreen();
            break;
        case 17:
            numbersOfDay(t, n);
            clearScreen();
            break;
        case 18:
            ktraInThuong(ch);
            getchar();
            clearScreen();
            break;
        case 19:
            ktraInHoa(ch);
            getchar();
            clearScreen();
            break;
        case 20:
            ktraChuCai(ch);
            getchar();
            clearScreen();
            break;
        case 21:
            ktraChuSo(ch);
            getchar();
            clearScreen();
        case 22:
            hoaThuong(ch);
            getchar();
            clearScreen();
        case 23:
            thuongHoa(ch);
            getchar();
            clearScreen();
        case 24:
            chuKeTiep(ch);
            getchar();
            clearScreen();
        case 25:
            validTriangle(a, b, c);
            clearScreen();
        case 26:
            ktraTamGiac(a, b, c);
            clearScreen();
        case 27:
            yearWeekDay(n);
            clearScreen();
        default:
            break;
        }

    } while (chon != 0);

    return 0;
}