#include <stdio.h>
#include <string.h>

// Bai 1.
int demKiTuInThuong(char c[])
{
    int count = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 'a' && c[i] <= 'z')
            count++;
    }
    return count;
}

// Bai 2.
char *strlower(char c[])
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
            c[i] += 32;
    }
    return c;
}

// Bai 3.
char* strupper(char c[])
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= 'a' && c[i] <= 'z')
            c[i] -= 32;
    }
    return c;
}

// Bai 4.
char upperToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

// Bai 5.
char lowerToUpper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

// Bai 6.
int isalpha(char c)
{
    if (c >= 'A' && c <= 'z') return 1;
    return 0;
}

// Bai 7.
int islower(char c)
{
    if (c >= 'a' && c <= 'z') return 1;
    return 0;
}

// Bai 8.
int isupper(char c)
{
    if (c >= 'A' && c <= 'Z') return 1;
    return 0;
}

// Bai 9.
int isdigit(char c)
{
    if (c >= '0' && c <= '9') return 1;
    return 0;
}

// Bai 10.
int isDigitOrAlpha(char c)
{
    if ((c >= 'A' && c <= 'z') || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

// Bai 11.
int strlen(char c[])
{
    int count = 0;
    while (c[count] != '\0')
        count++;
    return count;
}

// Bai 12.


int main()
{
    char c[100];
    printf("Enter a string: ");
    gets(c);
    printf("%d", strlen(c));
    return 0;
}