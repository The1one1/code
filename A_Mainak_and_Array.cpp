#include<bits/stdc++.h>
using namespace std;
// #define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x: v) cin >> x;
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = INT_MIN;

        int maxi = *max_element(v.begin() + 1, v.end());
        int mini = *min_element(v.begin(), v.end() - 1);

        ans = max({ans, maxi - v[0], v[n-1] - mini});
        
        for(int i = 1; i < n; i++) {
            ans = max(ans, v[i-1] - v[i]);
        }
        if(ans == INT_MIN) cout << 0 << endl;
        else cout << ans << endl;
    }
}