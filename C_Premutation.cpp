#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n - 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1; j++) {
                cin >> a[i][j];
            }
        }

        vector<int> pos = a[0];
        sort(pos.begin(), pos.end());
        int miss_val = 0, start = -1, end = n;
        for(int i = 0; i < n; i++) {
            if(pos[i] != i + 1) {
                miss_val = i + 1;
                break;
            }
        }

        int ind = 0, flagInd = 0;
        for(int i = 1; i < n; i++) {
            while(flagInd < n - 1 and a[i][ind] != miss_val) {
                flagInd++;
            }
        }
    }
}