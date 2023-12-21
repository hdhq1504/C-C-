#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int m, n; cin >> m >> n;
        int a[500][500];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }

        int res[500][500];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = a[i][j];
                for (int k = 0; k < 8; k++)
                {
                    int imoi = i + dx[k];
                    int jmoi = j + dy[k];
                    if (imoi >= 0 && imoi < n && jmoi >= 0 && jmoi < n)
                        sum += a[imoi][jmoi];
                }
                res[i][j] = sum;
            }
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << res[i][j] << " ";

            cout << endl;
        }
    }
    return 0;
}