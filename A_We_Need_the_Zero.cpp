#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < (1 << 8); ++i) {
            int ans = a[0] ^ i;
            for (int j = 1; j < n; j++) {
                ans = ans ^ (a[j] ^ i);
            }
            if (ans == 0) {
                cout << i << endl;
                goto last;
            }
        }

        cout << "-1\n";
    last:;
    }
}