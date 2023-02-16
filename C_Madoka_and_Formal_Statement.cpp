#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int ans = b.back() - a.back();

        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == b[i]) continue;
            int x = b[i] - a[i];
            if(x < 0) {
                ans = -1;
                break;
            }
            else {
                if(i == n - 1)
                    a[i] = b[i];
                else {
                    a[i] = min(b[i], a[i + 1] + 1);
                    if(a[i] != b[i]) {
                        ans = -1;
                        break;
                    }
                }
            }
        }
        
        if(ans > 0) {
            if(a.back() > a[0] + 1) {
                ans = -1;
            }
        }

        cout << ((ans == -1) ? "NO" : "YES") << endl;
    }
}