#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];
        map<int, pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            if(m[c[i]].first == 0)
                m[c[i]] = {1, i};
            else if(m[c[i]].second - i == 1 or m[c[i]].second - i >= 3) {
                m[c[i]].first++;
                m[c[i]].second = i;
            }
        }

        int ans = 0;
        for(auto &[key, value]: m) {
            int x = value.first;
            ans = max(ans, x);
        }

        cout << ans << endl;
    }
}