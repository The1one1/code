#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int> (n , 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
    }
}