#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        int l = 0, r = n -1;
        while(l < r and str[l] not_eq str[r]) {
            l++, r--;
        }

        if(l > r) cout << 0 << endl;
        else cout << r - l + 1 << endl;
    }
}