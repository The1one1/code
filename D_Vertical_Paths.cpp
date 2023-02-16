#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> adj[n + 1], vis(n + 1, 0), par(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> par[i];
            adj[par[i]].push_back(i);
            adj[i].push_back(par[i]);
        }

        if(n == 1) {
            cout << "1\n1\n1\n";
            continue;
        }
        vector<int> leaf;
        for(int i = 1; i <= n; i++) {
            if(adj[i].size() == 1) {
                leaf.push_back(i);
            }
        }

        vector<vector<int> > ans;
        for(int i = 0; i < leaf.size(); i++) {
            int x = leaf[i];
            vector<int> temp;
            while(vis[x] == 0) {
                temp.push_back(x);
                vis[x] = 1;
                x = par[x];
            }
            ans.push_back(temp);
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].size() << "\n";
            for(int j = ans[i].size() - 1; j >= 0; j--) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}