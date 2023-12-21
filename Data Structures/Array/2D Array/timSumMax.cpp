#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int a[500][500];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }

        long long ans = -1e18;
        vector<int> row; // Lưu các dòng có tổng lớn nhất
        for (int i = 0; i < m; i++)
        {
            long long sum = 0;
            for (int j = 0; j < n; j++)
                sum += a[i][j];

            if (sum > ans)
            {
                ans = sum;
                row.clear();
                row.push_back(i);
            }
            else if (sum == ans)
                row.push_back(i);
        }
        cout << ans << endl;
        for (int x : row)
            cout << x + 1 << " ";
        cout << endl;
    }
    return 0;
}