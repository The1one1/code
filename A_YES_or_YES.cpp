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
        string str;
        cin >> str;
        if ((str[0] == 'y' or str[0] == 'Y') && 
            (str[1] == 'e' or str[1] == 'E') && 
            (str[2] == 's' or str[2] == 'S')) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}