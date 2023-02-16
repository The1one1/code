#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long
const int N = 10000;
vector<int> adj[N];

int dfs(int n, vector<int> a, vector<int> b){
    queue<int> q;
    vector<int> v(n+1), visited(n+1);
    q.push(1);
    int task =0 ;
    visited[1] = 1;

    if(a[1] != b[1])
    {
        task++;
        a[1] = b[1];
        v[1]++;
        for(auto &child: adj[1]){
            v[child] += v[1];
        }
    }
    cout <<"task="<<task<<endl;
    cout <<"hellow\n"<<flush;

    while(!q.empty()){
        int par = q.front();
        q.pop();

        for(auto &child : adj[par]){
            if(visited[child] == 1){
                continue;
            }
            visited[child] = 1;
            q.push(child);
            a[child] = (a[child] + v[child]%2)%2;

            if(a[child] != b[child]){
                a[child] = b[child];
                v[child]++;
                task++;
            }

            for(auto &it : adj[child]){
                if(visited[it]) continue;
                v[it] += v[child];
            }
        }
    }
    cout <<"task="<<task<<endl;
    return task;
}

signed main(){
    inout;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < n + 5; i++){
            adj[i].clear();
        }
        vector<int> a(n+1), b(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        for(int i = 1; i < n; i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << dfs(n, a, b) << endl;
    }
}