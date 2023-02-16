#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, w; cin >> n >> w;
        // vector<int> wt(n);
        multiset<int> wt;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            wt.insert(x);
        }
        int cnt = 0;
        while(wt.size()) {
            cnt++;
            int curr = w;
            while(wt.size() && *(--wt.end()) <= curr) {
                curr -= *(--wt.end());
                wt.erase(--wt.end());
            }

            while(wt.size() && *(--wt.end()) > curr && curr > 0) {
                auto it = wt.upper_bound(curr);
                if(it == wt.begin()) break;
                it--;
                curr -= *it;
                wt.erase(it);
            }
        }
        cout << cnt << endl;
    }   
}