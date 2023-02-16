#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        int neg = 0, minVal = INT_MAX;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < 0) neg++;
            a[i] = abs(a[i]);
            minVal = min(minVal, a[i]);
        }

        if(neg == 0 or minVal == 0 or neg % 2 == 0) {
            cout << accumulate(a.begin(), a.end(), 0LL) << endl;
        }
        else {
            cout << accumulate(a.begin(), a.end(), 0LL) - 2 * minVal << endl;
        }
    }
}