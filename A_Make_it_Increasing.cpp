#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> v(n), b(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i];

    int ans = 0, ans1 = 1e18;

    for(int i = 0; i < n; i++) {
        fill_n(b.begin(), n, 0);
        ans = 0;
        for(int j = i - 1; j >= 0; j--) {
            int quo = b[j + 1] / v[j];
            b[j] = (quo + 1) * v[j];
            ans += (quo + 1);
        }

        for(int j = i + 1; j < n; j++) {
            int quo = b[j - 1] / v[j];
            b[j] = (quo + 1) * v[j];
            ans += (quo + 1);
        }
        ans1 = min(ans1, ans);
    }
    cout << ans1 << endl;
}