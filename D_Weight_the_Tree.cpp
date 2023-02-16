#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<bool> goodNode;
vector<int> nodeWeight;

int dfs(int node, int par) {
    if(par != 0 and adj[node].size() == 1 and goodNode[par] == false) {
        nodeWeight[node] = 1;
        return 1;
    }
    int ans = 0;
    for (auto &child : adj[node]) {
        if (child == par)
            continue;
        if (goodNode[par]) {
            ans += dfs(child, node);
            nodeWeight[node] = 1;
        }
        else {
            // treat as good node
            goodNode[node] = true;
            int x = 1 + dfs(child, node);

            // treat as bad node
            goodNode[node] = false;
            int y = dfs(node, child);

            // choose the better one
            if (x > y) {
                goodNode[node] = true;
                nodeWeight[node] = adj[node].size();
                ans += x;
            }
            else
                ans += y;
        }
    }
    return ans;
}

signed main() {
    int n; cin >> n;
    adj = vector<vector<int>>(n + 1);
    goodNode = vector<bool>(n + 1, false);
    nodeWeight = vector<int>(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << dfs(1, 0) << endl;
    for_each(nodeWeight.begin()+1, nodeWeight.end(), [&](auto it){ cout << it << " "; });
}