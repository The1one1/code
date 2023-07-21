#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        int ans = 0, i = 0, j = n-1;

        while(i < j) {
            ans += (a[j] - a[i]);
            i++, j--;
        }

        cout << ans << endl;
    }
}