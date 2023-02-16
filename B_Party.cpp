#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m; 
        vector<pair<int, int>> a(n, {0, 0});
        vector<int> adj[n + 1];
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }

        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[y].push_back(x);
            adj[x].push_back(y);
        }

        vector<int> edgeCnt(n + 1);
        for(int i = 1; i <= n; i++) {
            edgeCnt[i] = adj[i].size();
        }

        sort(a.begin(), a.end());
        int p = m, i = 0, ans = 0;
        while(p >= 0 and p % 2 != 0) {
            if(adj[a[i].second].size() > 0) {
                for(auto x: adj[a[i].second]) {
                    edgeCnt[x]--;
                    if(edgeCnt[x] < 0)
                        edgeCnt[x] = 0;
                }
                ans += a[i].first;
            }
            p -= edgeCnt[a[i].second];
            adj[a[i].second].clear();
            i++;
        }
        cout << ans << endl;
    }
}