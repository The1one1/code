#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0 and !mp.empty()) {
                ans += (--mp.end())->first;
                int x = --(--mp.end())->second;
                if(x == 0) {
                    mp.erase(--mp.end());
                }
                // cout << "ans=" << ans << endl;
            }
            else {
                mp[arr[i]]++;
            }
        }
        cout << ans << endl;
    }
}