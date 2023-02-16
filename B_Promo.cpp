#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    
        int n, q; cin >> n >> q; 
        vector<int> p(n+1);

        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        sort(p.begin()+1, p.end(), greater<int>());  

        for(int i = 1; i<= n; i++){
            p[i] = p[i] + p[i-1];
        }

        while(q--) {
            int x, y; cin >> x >> y;
            cout << p[x] - p[x - y] << endl;
        }
    }
