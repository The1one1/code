#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        vector<int> arr(n);
        for(auto &it: arr) cin >> it;

        int i = 0, ind = 0;
        while(i < n and str[i] != '0') {
            i++;
        }
        ind = i;
        if(i == n) {
            cout << accumulate(arr.begin(), arr.end(), 0) << endl;
            continue;
        }
        for(int i = ind + 1; i < n; i++) {
            if(str[i] == '1') {
                if(arr[i] <= arr[ind]) {
                    swap(str[i], str[ind]);
                    ind = i;
                }
            }
            else {
                ind = i;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += ((str[i] == '1') ? arr[i] : 0);
        }
        cout << ans << endl;
    }
}