#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        int sum = 0;
        bool flag = false;
        for (auto &it : a)
        {
            cin >> it;
            sum += abs(it);
            if (it < 0)
            {
                flag = true;
            }
        }

        int j = 0;
        int ans = 0;
        while (j < n and a[j] >= 0)
        {
            j++;
        }

        while (j < n)
        {
            if (a[j] > 0)
            {
                ans++;
                while (j < n and a[j] >= 0)
                {
                    j++;
                }
                if (j == n)
                {
                    goto last;
                }
            }
            j++;
        }
        if (a.back() <= 0 and flag)
        {
            ans++;
        }
    last:;

        cout << sum << " " << ans << endl;
    }
}