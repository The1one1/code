#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int> (n, 0));
        int l = 1, r = n*n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v[i][j] = ((j % 2 == 0) ? l++ : r--);
            }
            i++;
            if(i < n) {
                for(int j = n-1; j >= 0; j--) {
                    v[i][j] = ((j % 2 != 0) ? l++ : r--);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << v[i][j] <<" ";
            }cout << endl;
        }
    }
}