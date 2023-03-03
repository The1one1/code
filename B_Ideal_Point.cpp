#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        bool len0 = false, start = false, end = false;

        for(auto &it: v) {
            if(k >= it.first and k <= it.second) {
                if(it.first == k) start = true;
                if(it.second == k) end = true;
                if(it.first == it.second) {
                    len0 = true;
                    break;
                }
            }
        }

        if(len0 or (start and end)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}