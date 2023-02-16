#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long
vector<vector<int> > adj;
vector<pair<int, int> > range;
int cnt = 0;

int dfs(int node){
    int x = 0;
    for(auto &child: adj[node]){
        x += dfs(child);
    }
    if(x < range[node].first or adj[node].size() == 0){
        cnt++;
        x = range[node].second;
    }
    return min(x, range[node].second);
}

signed main() {
    int t; cin >> t;
    while(t--){
        cnt = 0;
        int n; cin >> n;

        adj = vector<vector<int> >(n+1);
        for(int i = 2; i <= n; i++){
            int p; cin >> p;
            adj[p].push_back(i);
        }

        range = vector<pair<int, int> >(n + 1, {0, 0});
        for(int i = 1; i <= n; i++){
            int x, y; cin >> x >> y;
            range[i] = {x, y};
        }

        int x = dfs(1);
        cout << cnt << endl;
    }
}