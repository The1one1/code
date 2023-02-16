#include <bits/stdc++.h>
using namespace std;
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
        for (auto &it : a)
            cin >> it;

        sort(a.begin(), a.end());

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
                cnt1++;
            else if (a[i] == a[n - 1])
                cnt2++;
        }
        if (a[0] == a[n - 1])
            cout << (n - 1) * n << endl;
        else
            cout << 2 * cnt1 * cnt2 << endl;
    }
}