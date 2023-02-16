#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        int x, y;
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j]=='R'){
                    x = i;
                    y = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        flag = false;
        int x2, y2;
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(v[i][j]=='R'){
                    x2 = i;
                    y2 = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(x == x2 and y == y2){
            cout <<"YES\n";
        }
        else cout <<"NO\n";
    }
}