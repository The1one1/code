#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, l, r; cin >> n >> l >> r;
        vector<int> v;
        for(int i = 1; i <= n; i++) {
            int x = l/i;
            int y = i * x;
            if(y >= l and y <= r) {
                v.push_back(y);
                continue;
            }
            else {
                y = i * (x + 1);
                if(y >= l and y <= r) {
                    v.push_back(y);
                    continue;
                }
                cout << "NO\n";
                goto last;
            }
        }
        
        cout << "YES\n";
        for(auto &it: v) {
            cout << it<<" ";
        }
        cout << endl;
        last:;
    }
}