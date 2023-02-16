#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> adj;
vector<int> gcd1, value;

void gcdDFS(int node, int par) {
    gcd1[node] = value[node];
    for (int &child : adj[node]) {
        if (child != par) {
            gcdDFS(child, node);
            gcd1[node] = __gcd(gcd1[node], gcd1[child]);
        }
    }
}

int maxDFS(int node, int par) {
    vector<int> q;
    int gcdSum = 0;
    for (auto &child : adj[node]) {
        if (child != par) {
            q.push_back(child);
            gcdSum += gcd1[child];
        }
    }
    int ans = 0;
    for (int i = 0; i < q.size(); i++) {
        int child = q[i];
        ans = max(ans, gcdSum - gcd1[child] + maxDFS(child, node));
        ans = max(ans, gcdSum);
    }
    return ans;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        adj = vector<vector<int>>(n + 2);
        value = gcd1 = vector<int>(n + 2);

        for (int i = 1; i <= n; i++)
            cin >> value[i];

        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        gcdDFS(1, 0);
        cout << maxDFS(1, 0) << endl;
    }
}