#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e9 + 7;
vector<int> level;
vector<vector<int>> adj; 
map<int, int> m;

int dfs(int node, int c) {
    queue<int> q;
    q.push(node);
    level[node] = 1;
    int ans = 1;
    while(! q.empty()) 
    {
        int child = q.front();
        if(level[child] > 1) m[child] = 1;
        q.pop();

        for(auto &it: adj[child]) 
        {
            m[child]++;
            q.push(it);
            level[it] = level[child] + 1;
            ans = (ans%N * (c - m[child])%N)%N;
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, c; cin >> n >> c;
	adj = vector<vector<int>>(n+1);
	level = vector<int> (n + 1, 0);
	for(int i = 1; i < n; i++) {
	    int u, v; cin >> u >> v;
	    adj[u].push_back(v);
	}
	int ans = dfs(1, c);
	
    cout << (ans%N * c % N)%N << endl;
}

