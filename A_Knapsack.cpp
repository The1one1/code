#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, W; cin >> n >> W;
        vector<pair<int, int>> w;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            w.push_back({x, i + 1});
        }

        sort(w.begin(), w.end(), [](auto x, auto y) { return x.second > y.second; });

        int minW = ceil(W/2.0), sum = 0;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            if(w[i].first <= W) {
                sum += w[i].first;
                v.push_back({w[i].second, w[i].first});
                if(sum >= minW) {
                    break;
                }
            } 
        }
    }
}