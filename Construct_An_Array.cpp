#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 1, j = n;

        while (n > 1)
        {
            cout << i * j << " " << (i + 1) * j << " ";
            i++, j--, n -= 2;
        }
        if(n == 1){
            cout << i*j;
        }
        cout << endl;
    }
}