#include<bits/stdc++.h>
using namespace std;
signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> v(n+2, n + 1);

        while (m--) {
            int a, b; cin >> a >> b;
            int l = min(a, b);
            int r = max(a, b);
            v[l] = min(v[l], r);
        }

        long  long int ans = 0;
        int cnt = 0, range = n + 1; 
        for (int i = n + 1; i >= 1; i--) {
            if(v[i] != i) {
                range = min(range, v[i]);
                v[i] = range;
            }
        }
        for(int i = 1; i <= n; i++) {
            ans += (v[i] - i);
        }
        cout << ans << endl;
    }
}