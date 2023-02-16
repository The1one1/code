#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        vector<int> cost(n + 1, 0);
        for(int i = 1; i <= n; i++) cin >> cost[i];
        for(int i = 1; i <= n; i++) {
            cost[i] = i + cost[i];
        }

        sort(cost.begin(), cost.end());
        int cnt=  0;
        for(int i = 1; i <= n; i++) {
            if(c - cost[i] >= 0) {
                c -= cost[i];
                cnt++;
            }
            else break;
        }
        cout << cnt << endl;
    }
}