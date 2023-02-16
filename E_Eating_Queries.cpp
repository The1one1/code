#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        for(auto &it: a) cin >> it;
        sort(a.begin(), a.end(),[&](auto x, auto y){return x >y;});
        vector<int> preSum = a;
        for(int i = 1; i < n; i++) {
            preSum[i] = preSum[i] + preSum[i-1];
        }

        while(q--) {
            int x; cin >> x;
            auto it = lower_bound(preSum.begin(), preSum.end(), x);
            if(it != preSum.end()) {
                cout << it - preSum.begin() + 1 << endl;
            }
            else {
                cout << "-1\n";
            }
        }

    }
}