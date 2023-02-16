#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                cnt += ((v[j] & (1 << i)) > 0);
            }
            cnt = n - cnt;
            if(k >= cnt) {
                ans += (1 << i);
                k = k - cnt;
            }
        }
        cout << ans << endl;
    }
}