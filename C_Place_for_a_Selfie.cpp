#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        vector<int> a(m), b(m), c(m);

        for (int i = 0; i < m; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        for (int i = 0; i < m; i++) {
            if (a[i] * c[i] < 0) {
                cout << "NO\n";
            }
            else {
                float l = b[i] * (1.0) - sqrt(4 * 1.0 * a[i] * c[i]);
                float r = b[i] * (1.0) + sqrt(4 * 1.0 * a[i] * c[i]);
                // cout << l << " " << r << endl;
                if(int(l) == l ) l = (int)l - 1;
                else l = (int)l;
                if(int(r) == r) r = (int)r - 1;
                else r = (int)r;
                
                if(l >= r) {
                    cout << "NO\n";
                }
                else {
                    cout << "YES\n";
                    cout << r << endl;
                }
            }
        }cout << endl;
    }
}