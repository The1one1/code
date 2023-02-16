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
        if(n % 2 not_eq 0 or n == 2) {
            cout <<"-1\n";
            continue;
        }
        n = n/2;
        //min bus
        cout << (n/3 + (n%3 == 0 ? 0 : 1)) << " ";

        //max bus
        cout << n/2 <<"\n";

    }
}