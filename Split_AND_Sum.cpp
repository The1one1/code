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
        vector<bitset<30>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            v.push_back((a[i]));
            // cout <<v[i]<<endl;
        }
        int j = 0;
        vector<int> ans;
        while (j < 30)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i][j] == 1)
                    ans.push_back(i);
            }
            if (ans.size() > 1)
                break;
            j++;
            ans.clear();
        }

        if (ans.size() <= 1)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << ans.size() << endl;
            ans[ans.size() - 1] = n - 1;
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " " << ans[j] + 1 << endl;
                i = ans[j];
                j++;
            }
        }
    }
}