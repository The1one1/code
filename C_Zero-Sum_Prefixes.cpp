#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int ans = 0;
        vector<int> preSum(n);
        preSum[0] = a[0];
        bool flag = (a[0] != 0);
        for (int i = 1; i < n; i++)
        {
            preSum[i] = preSum[i - 1] + a[i];
            if(a[i] == 0) flag = false;
            if(flag and preSum[i] == 0) {
                ans++;
            }
        }

        for (int i = 0, j = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                int maxFreq = 1;
                map<int, int> freq;
                freq[preSum[i]] = 1;
                for (j = i + 1; j < n; j++)
                {
                    if (a[j] == 0) break;
                    maxFreq = max(maxFreq, ++freq[preSum[j]]);
                }
                ans += maxFreq;
                i = j - 1;
            }
        }
        cout << ans << endl;
    }
}