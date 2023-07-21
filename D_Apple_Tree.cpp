#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int node, int par, vector<int> adj[], vector<int> &rootCnt) {
    for(auto it : adj[node]) {
        if(it == par) {
            continue;
        }
        dfs(it, node, adj, rootCnt);
    }
    if(adj[node].size() == 1 and node != 1) {
        rootCnt[node] = 1;
    }
    rootCnt[par] += rootCnt[node];
}


signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> adj[n + 1];

        for(int i = 0; i < n - 1; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> rootCnt(n + 1, 0);
        dfs(1, 0, adj, rootCnt);
        int q; cin >> q;
        while(q--) {
            int x, y; cin >> x >> y;
            cout << rootCnt[x] * rootCnt[y] << endl;
        }
    }
}