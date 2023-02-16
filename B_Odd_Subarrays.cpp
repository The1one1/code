#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int x = -1, ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j > x; j--)
            {
                if (a[j] > a[i])
                {
                    x = i;
                    ans++;
                    break;
                }

                else break;
            }
        }
        cout << ans << endl;
    }
}