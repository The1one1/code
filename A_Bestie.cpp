#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(auto &it : a) cin >> it;

        int gcd = a[0];
        for(int i = 1; i < n; i++) {
            gcd = __gcd(gcd, a[i]);
        }

        if(gcd == 1) {
            cout << 0 << endl;
        }
        else if(__gcd(gcd, n) == 1) {
            cout << 1 << endl;
        }
        else if(__gcd(gcd, n-1) == 1) {
            cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }
}