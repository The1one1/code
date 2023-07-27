#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> p;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            p.push_back({x, y});
            if(x <= 10) {
                ans = max(ans, y);
            }
        }

        int ind = 0;
        for(int i = 0; i < n; i++) {
            if(p[i].first <= 10) {
                if(p[i].second == ans) {
                    ind = i;
                    break;
                }
            }
        }

        cout << ind + 1 << endl;
    }
    
}