#include <bits/stdc++.h>
using namespace std;

// Input:
// 1
// 4 4
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// Output:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
//
// 1  - 2  - 3  - 4
//                |
// 5  - 6  - 7    8
// |         |    |
// 9    10 - 11   12
// |              |
// 13 - 14 - 15 - 16

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

        int h1 = 0, h2 = m - 1, c1 = 0, c2 = n - 1;
        vector<int> v;
        while (h1 <= h2 && c1 <= c2)
        {
            // Xay dung dong tren cung
            for (int i = c1; i <= c2; i++)
                v.push_back(a[h1][i]);
            ++h1;

            // Xay dung dong ben phai
            for (int i = h1; i <= h2; i++)
                v.push_back(a[i][c2]);
            --c2;

            // Xay dung dong duoi cung
            if (h1 <= h2)
            {
                for (int i = c2; i >= c1; i--)
                    v.push_back(a[h2][i]);
                --h2;
            }

            // Xay dung dong ben trai
            if (c1 <= c2)
            {
                for (int i = h2; i >= h1; i--)
                    v.push_back(a[i][c1]);
                ++c1;
            }
        }
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << " ";

        cout << endl;
    }
    return 0;
}