#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void xuatHoLot_Ten(char hoten[])
{
    int i = 0, j = 0;
    int n = strlen(hoten);

    for (i = n - 1; i >= 0; i--)
    {
        if (hoten[i] == ' ')
            break;
    }

    char holot[30];
    for (int k = 0; k < i; k++)
    {
        holot[k] = hoten[k];
        j = k + 1;
    }
    holot[j] = '\0';
    printf("Ho lot: %s\n", holot);

    char ten[10];
    for (int k = i + 1; k < n; k++)
    {
        ten[k - i - 1] = hoten[k];
        j = k - i;
    }
    ten[j] = '\0';
    printf("Ten: %s", ten);
}

void insertSubString(char mainStr[], char subStr[], int pos)
{
    int m = strlen(mainStr);
    int n = strlen(subStr);
    char *kq;
    int mn = m + n;
    kq = new char[mn];
    
    if (pos < 0 || pos > m)
        return;

    int i = 0, j = 0, k = 0;
    while (i < pos)
        kq[k++] = mainStr[i++]  ;

    while (j < n)
        kq[k++] = subStr[j++];

    while (i < m)
        kq[k++] = mainStr[i++];

    kq[mn] = '\0';
    strcpy(mainStr, kq);
    printf("%s", mainStr);
}

int main()
{
    char mainStr[30], subStr[30];
    int pos;
    gets(mainStr);
    gets(subStr);
    scanf("%d", &pos);
    insertSubString(mainStr, subStr, pos);
    return 0;
}