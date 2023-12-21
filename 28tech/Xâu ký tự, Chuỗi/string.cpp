#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Đếm số lần xuất hiện của các kí tự trong xâu 3
void demKiTuXuatHienNhieuNhat(char c[])
{
    int count[256] = {0};
    for (int i = 0; i < strlen(c); i++)
        count[c[i]]++;

    int res = 0;
    char kt;
    for (int i = 0; i < 256; i++)
    {
        if (count[i])
        {
            if (count[i] >= res)
            {
                res = count[i];
                kt = (char)i;
            }
        }
    }
    printf("%c", kt);
}

// Các kí tự xuất hiện ở cả 2 xâu
void lietKeKiTuXuatHien2Xau(char c1[], char c2[])
{
    int cnt[256] = {0};
    for (int i = 0; i < strlen(c1); i++)
        cnt[c1[i]] = 1;
    
    for (int i = 0; i < strlen(c2); i++)
    {
        if (cnt[c2[i]])
            cnt[c2[i]] = 2;
    }

    for (int i = 0; i < 256; i++)
    {
        if (cnt[i] == 2)
            printf("%c", i);
    }
}

// Liệt kê các kí tự chỉ xuất hiện trong xâu thứ nhất mà không xuất hiện trong xâu thứ 2
void lietKeKiTuXuatHienXau1(char c1[], char c2[])
{
    int cnt[256] = {0};
    for (int i = 0; i < strlen(c1); i++)
        cnt[c1[i]] = 1;
    
    for (int i = 0; i < strlen(c2); i++)
    {
        if (cnt[c2[i]] == 1)
            cnt[c2[i]] = 0;
    }

    for (int i = 0; i < 256; i++)
    {
        if (cnt[i] != 0)
            printf("%c", i);
    }
}

// Liệt kê các kí tự xuất hiện ở 1 hoặc 2 xâu
void lietKeKiTuXuatHien1Trong2Xau(char c1[], char c2[])
{
    int cnt[256] = {0};
    for (int i = 0; i < strlen(c1); i++)
        cnt[c1[i]] = 1;
    
    for (int i = 0; i < strlen(c2); i++)
        cnt[c2[i]] = 1;

    for (int i = 0; i < 256; i++)
    {
        if (cnt[i] != 0)
            printf("%c ", i);
    }
}

// Kiểm tra xâu nhập vào có phải là xâu Pangram không
int pangram(char c[])
{
    strlwr(c);
    int cnt[26] = {0};
    for (int i = 0; i < strlen(c); i++)
        cnt[c[i] - 'a'] = 1;

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] == 0)
            return 0;
    }
    return 1;
}

// Kiểm tra xâu nhập vào có phải là xâu Palindrome không
int palindrome1(char c[])
{
    int l = 0;
    int r = strlen(c) -1;
    while (l <= r)
    {
        if (c[l] != c[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}

// Kiểm tra có thể biến xâu thành xâu Palindrome không
int palindrome2(char c[])
{
    int dem = 0;
    int l = 0, r = strlen(c) - 1;
    while (l <= r)
    {
        if (c[l] != c[r]) 
            dem++;
        l++;
        r--;
    }

    if (strlen(c) % 2 != 0 && dem <= 0)
        return 1;
    if (strlen(c) % 2 == 0 && dem == 1)
        return 1;
}

// tách chuỗi bằng hàm strtok()
void tachChuoi(char c[])
{
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    } 
}

// Đếm số lượng từ trong câu
void demSoLuongTu(char c[])
{
    int count = 0;
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " ");
    }
    printf("%d", count);
}

// Liệt kê các từ in hoa trong câu
int check(char c[])
{
    for (int i = 0; i < strlen(c); i++)
    {
        if (!isupper(c[i]))
            return 0;
    }
    return 1;
}

void lietKeTuInHoa(char c[])
{
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        if (check(token))
            printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    getchar();
    while (t--)
    {
        char c[1005];
        gets(c);
        lietKeTuInHoa(c);
    }
    return 0;
}