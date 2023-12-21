#include <stdio.h>

// Bai 1. Dem so dep
int isPrime(int n) // Kiem tra SNT
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int isPrimeDigits(int n) // Kiem tra tung chu so cua so do phai la SNT hay khong
{
    while (n > 0)
    {
        int chuSo = n % 10;
        if (!isPrime(chuSo))
            return 0;
        n /= 10;
    }
    return 1;
}
int demSoDep(int a, int b)
{
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i) && isPrimeDigits(i))
        {
            int sum = 0;
            int temp = i;
            while (temp > 0)
            {
                int mod = temp % 10;
                sum += mod;
                temp /= 10;
            }
            if (isPrime(sum))
                count++;
        }
    }
    return count;
}

// Bai 2. Tim so hoan hao
int isPerfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum == n;
}
void timSoHoanHao(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isPerfectNumber(i))
            printf("%d ", i);
    }
}

// Bai 3. So tang giam
// Bai 4. Tim So dep (Fibonacci)
long long fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int isFibonacci(int n)
{
    int i = 1;
    while (fibonacci(i) <= n)
    {
        if (fibonacci(i) == n)
            return 1;
        i++;
    }
    return 0;
}
int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int mod = n % 10;
        sum += mod;
        n /= 10;
    }
    return sum;
}
void lietKeSoDep(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i) && isFibonacci(digitSum(i)))
            printf("%d ", i);
    }
}

// Bai 5. Liet ke n so Fibonacci
void printFibonacci(int n)
{
    for (int i = 0; i < n; i++)
        printf("%lld ", fibonacci(i));
}

// Bai 6. Phan tich thua so nguyen to
void thuaSoNguyenTo(int n)
{
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }
}

// Bai 7. So dep
// Bai 8. So dep
int isBeautifulNumber(int num)
{
    int originalNum = num;
    int reverseNum = 0;
    int digitSum = 0;

    // Đảo ngược số và tính tổng chữ số
    while (num > 0)
    {
        int digit = num % 10;
        reverseNum = reverseNum * 10 + digit;
        digitSum += digit;
        num /= 10;
    }

    // Kiểm tra tính chất thuận nghịch và tổng chữ số chia hết cho 10
    return (originalNum == reverseNum && digitSum % 10 == 0);
}

// Hàm đếm số lượng số đẹp với số chữ số nhất định
int countBeautifulNumbers(int numDigits)
{
    int lowerLimit = 1;
    int upperLimit = 10;

    // Tìm giới hạn dưới và giới hạn trên với số chữ số nhất định
    for (int i = 1; i < numDigits; i++)
    {
        lowerLimit *= 10;
        upperLimit *= 10;
    }

    int count = 0;

    // Lặp qua các số thuận nghịch trong khoảng
    for (int num = lowerLimit; num < upperLimit; num++)
    {
        if (isBeautifulNumber(num))
            count++;
    }

    return count;
}

// Bai 9
void soNguyenToTrongDoan(int a, int b)
{
    while (a <= b)
    {
        if(isPrime(a))
            printf("%d ", a);
        a++;
    }
}

// Bai 10
void demChanLe(int n)
{
    int countEven = 0;
    int countOdd = 0;
    int countDigit = 0;
    while (n > 0)
    {
        int mod = n % 10;
        if (mod % 2 == 0)
            countEven++;
        else
            countOdd++;
        n /= 10;
        countDigit++;
    }
    if (countDigit > 9)
        return;
    else
        printf("%d %d", countOdd, countEven);
}

int main()
{
    int n;
    scanf("%d", &n);
    demChanLe(n);
    return 0;
}
