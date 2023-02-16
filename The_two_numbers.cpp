#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if(n == 2){
            cout << 0 << endl;
            continue;
        }
        if(n%2 == 1){
            int x = (n-1) / 2;
            x = x*(x+1);
            cout << x - 1 << endl;
            continue;
        }
        n = n / 2;
        int x = 0;
        if(n % 2 == 0){
            x = (n-1 )* (n+1);
        }
        else{
            x = (n-2) * (n+2);
        }
        cout << x - 1 << endl;
    }
}