#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int minDiff = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(a[i-1] > a[i]) {
                cout << 0 << endl;
                goto last;
            }
        }

        for(int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, a[i + 1] - a[i]);
        }
        cout << minDiff/2 + 1 << endl;
        last:;
    }
}