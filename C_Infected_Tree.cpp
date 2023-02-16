#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1e5 + 5;
vector<vector<int> > adj;

int fun(int node, int parent, vector<int> &NodeCnt)
{
    vector<int> q;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(adj[node][i] == parent) continue;
        q.push_back(adj[node][i]);
    }

    int ans = 0;
    if(q.size() == 1)
    {
        ans += NodeCnt[q[0]] - 1;
        return ans;
    }
    for(int i = 0; i < q.size(); i++){
        int temp = q[(i+1)%q.size()];
        ans = max(ans, NodeCnt[temp] - 1 + fun(q[i], node, NodeCnt));
    }
    return ans;
}

void node_child_cnt(int i, int parent, vector<int> &NodeCnt)
{
    NodeCnt[i] = 1;
    for(auto &child: adj[i])
    {
        if(child == parent) continue;
        node_child_cnt(child, i, NodeCnt);
        NodeCnt[i] += NodeCnt[child];
    }
}

int main()
{
    int test; cin >> test;
    while(test--)
    { 
        
        int n; cin >> n;
        adj = vector<vector<int> > (n + 1);
        vector<int> NodeCnt(n+1);
        
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        node_child_cnt(1, -1, NodeCnt);
        cout << fun(1, -1, NodeCnt) << endl;
    }
}