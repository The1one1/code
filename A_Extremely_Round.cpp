#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if(n <= 9) {
            cout << n << endl;
        }
        else {
            int x = (int)log10(n);
            int ans = x * 9 + (n / (int)pow(10, x));
            cout << ans << endl;
        }
    }
    
}