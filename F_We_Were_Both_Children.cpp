#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x <= n) {
                mp[x]++;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int cnt = 0;
            for(auto &it: mp) {
                if(i % it.first == 0) {
                    cnt += it.second;
                }
            }
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }
}