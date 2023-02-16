#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(m >= v[i]){
                m = m - v[i];
            }
            else{
                cnt += abs(m - v[i]);
                m = 0;
            }
        }
        cout << cnt << endl;
    }
}