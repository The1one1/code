#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> diff;
        vector<int> cnt;
        int ans = 1;
        for(int i = 1; i < n; i++) {
            diff.push_back(a[i] - a[i - 1]);
            if(a[i] - a[i - 1] <= k) {
                ans++;
            }
            else {
                cnt.push_back(ans);
                ans = 1;
            }
        }
        cnt.push_back(ans);
        sort(cnt.begin(), cnt.end(), greater<int>());
        cout << accumulate(cnt.begin(), cnt.end(), 0) - cnt[0] << endl;
    }
}