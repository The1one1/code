#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int m; cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        int max1 = *max_element(a.begin(), a.end());
        int max2 = *max_element(b.begin(), b.end());

        if ( max1 > max2) {
            cout << "Alice\nAlice\n";
        }
        else if (max1 < max2) {
            cout << "Bob\nBob\n";
        }
        else {
            cout << "Alice\nBob\n";
        }
    }
}