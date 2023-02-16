#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int, int>> adj[100006];
    vector<bool> visited;

    void dfs(int root, int &pathLength)
    {
        visited[root] = 1;
        for (auto &child : adj[root])
        {
            int start = child.first, weight = child.second;
            pathLength = min(pathLength, weight);
            if (visited[start] == 1) {
                continue;
            }
            dfs(start, pathLength);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        visited = vector<bool> (n + 1, 0);
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        int pathLength = INT_MAX;
        dfs(1, pathLength);
        return pathLength;
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            roads[i].push_back(x);
        }
    }
    Solution obj;
    cout << obj.minScore(n, roads) << endl;
}