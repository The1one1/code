#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        map<char, int> mp, m;
        for(int i = 0; i < n; i++) {
            mp[str[i]]++;
            m[tolower(str[i])]++;
        }

        int ans = 0;
        for(auto &it: m) {
            char lowerCh = it.first;
            char upperCh = toupper(lowerCh);
            int lowerCount = mp[lowerCh];
            int upperCount = mp[upperCh];
            ans += min(lowerCount, upperCount);
            int a = abs(lowerCount - upperCount);
            if(k > 0) {
                ans += min(k, a/2);
                k = k - min(k, a/2);
            }
        }
        cout << ans << endl;
    }
}