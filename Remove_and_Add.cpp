#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

int fun(int i, int j, int n)
{
    int x = i, y = n - j;
    return min((2 * x + y), (x + 2 * y));
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int i = 0, j = 0, ans = INT_MAX;
        while (i <= j and j < n)
        {
            if (m[a[j]] == 0)
                m[a[j++]]++;

            else
            {
                ans = min(ans, fun(i, j, n));
                while (a[i] != a[j])
                    m[a[i++]]--;

                i++;
                j++;
            }
        }
        ans = min(ans, fun(i, j, n));
        cout << ((ans == INT_MAX) ? 0 : ans) << endl;
    }
}