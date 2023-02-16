#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void fun(int x, int y, int cnt)
{
    if (x == y)
        cout << y + cnt << "\n";
    else
        cout << y + cnt + 1 << "\n";
}

signed main()
{
    int t; cin >> t;
    while (t--)
    {
        int x, y, cnt = 0;
        cin >> x >> y;
        if ((x == 0 && y > 0) || (x > 0 && y == 0))
            cout << -1 << "\n";
        else if (x == y)
            cout << x << "\n";
        else
        {
            if (x > y)
                swap(x, y);

            while (x <= y)
            {
                cnt++;
                x = x * 2;
            }
            x = x / 2;
            cnt--;
            fun(x, y, cnt);
        }
    }
}