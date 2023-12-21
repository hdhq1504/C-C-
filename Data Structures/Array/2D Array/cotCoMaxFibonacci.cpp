#include <bits/stdc++.h>
using namespace std;

set<long long> fibo;

void init()
{
    long long f[93];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++)
        f[i] = f[i - 1] + f[i - 2];

    for (int i = 0; i <= 92; i++)
        fibo.insert(f[i]);
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
    {
        int m, n; cin >> m >> n;
        long long a[500][500];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }

        int ans = -1, cot;
        long long sum = 0;
        int dem = 0;
        for (int j = 0; j < n; j++)
        {
            long long tmp = 0;
            for (int i = 0; i < m; i++)
            {
                if (fibo.count(a[i][j]) == 1)
                {
                    dem++;
                    tmp += a[i][j];
                }
            }

            if (dem > ans)
            {
                cot = j;
                ans = dem;
                sum = tmp;
            }
            else if (dem == ans)
            {
                if (sum > tmp)
                {
                    cot = j;
                    sum = tmp;
                }
            }
        }
        cout << cot + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            if (fibo.count(a[i][cot]) == 1)
                cout << a[i][cot] << " ";
        }
        cout << endl;
    }
    return 0;
}