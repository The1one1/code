#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str; 
        int ans = 1;
        for(int i = 1; i < n - 1; i++) {
            if(str[i-1] == str[i + 1]) {
                continue;
            }
            else {
                ans++;
            }
        }
        cout << ans << endl;
    }
}