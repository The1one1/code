#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        map<char, int> mp1, mp2;
        vector<int> pre(n, 0), suf(n, 0);
        for(int i = 0; i < n; i++) {
            mp1[str[i]]++;
            pre[i] = mp1.size();
        }
        for(int i = n - 1; i >= 0; i--) {
            mp2[str[i]]++;
            suf[i] = mp2.size();
        }
        int ans = mp1.size();
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, pre[i] + suf[i + 1]);
        }
        cout << ans << endl;
    }
}