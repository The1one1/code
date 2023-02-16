#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        map<int, int> mp;
        for(int i = 0; i < n; i++) mp[a[i]] = (i + 1);

        int ans = 0, ind = mp[1], num = -1;
        for(int i = 2; i <= n; i++) {
            if(ind < mp[i]) {
                ind = mp[i];
                continue;
            }
            else {
                num = i;
                break;
            }
        }

        if(num == -1) {
            cout << 0 << endl;
            continue;
        }
        else {
            cout << (n - num + 1)/ k + ((n - num + 1) % k == 0 ? 0 : 1) << endl;
        }
    }
}