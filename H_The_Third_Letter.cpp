#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(const vector<pair<int, int>> adj[], vector<bool> &vis, vector<int> &dis, int root)
{
    bool flag = true;
    vis[root] = true;
    for (const auto &child : adj[root])
    {
        int ChildNode = child.first;
        int ChildDis = child.second;
        int width = dis[root] + ChildDis;

        if (vis[ChildNode])
        {
            if (dis[ChildNode] != width)
            {
                return false;
            }
            continue;
        }
        dis[ChildNode] = width;
        flag = dfs(adj, vis, dis, ChildNode) and flag;
    }
    return flag;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> adj[n + 1];

        vector<bool> vis(n + 1);
        vector<int> dis(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});

            adj[a].emplace_back(b, d);
            adj[b].emplace_back(a, -d);
        }

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            flag = dfs(adj, vis, dis, i) and flag;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}