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
        int n; cin >> n;
        string str;
        cin >> str;
        int i = (str.size() / 2 )- 1;
        int cnt = 0;
        while (i >= 0)
        {
            if (str[i] == str[str.size()/2])
                cnt++;
            else
                break;
            i--;
        }

        if (str.size() % 2 == 1)
            cout << 2 * cnt + 1 << endl;
        else
            cout << 2 * cnt << endl;
    }
}