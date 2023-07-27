#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    vector<pair<int, int>> a;
    // {a, b}
    a.push_back({1, 0});
    a.push_back({0, 1});

    for (int i = 2; i < 35; i++)
    {
        int x = a[i - 2].first - a[i - 1].first;
        int y = a[i - 2].second - a[i - 1].second;
        a.push_back({x, y});
    }

    reverse(a.begin(), a.end());
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k > 33)
        {
            cout << 0 << endl;
        }
        else
        {
            int ans = n / 2 + (n % 2 == 0 ? 0 : 1);

            int aCnt = a[a.size() - k].first;
            int bCnt = a[a.size() - k].second;

            // cout << aCnt << " " << bCnt << endl;
            int aCnt1 = a[a.size() - k + 1].first;
            int bCnt1 = a[a.size() - k + 1].second;

            // cout << aCnt1 << " " << bCnt1 << endl;
            int cnt = 0;
            while (n - ans >= 0)
            {
                int x = aCnt * n + bCnt * ans;
                int y = aCnt1 * n + bCnt1 * ans;
                // cout << x << " " << y << endl;
                if (x >= 0 and y >= x)
                {
                    cnt++;
                }
                ans++;
            }

            cout << cnt << endl;
        }
    }
}