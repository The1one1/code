#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;

        map<string, pair<int, int>> mp;
        for(int i = 0; i < n - 1; i++) {
            string s = str.substr(i, 2);
            if(mp.find(s) == mp.end()) {
                mp[s].first = i;
                mp[s].second = i + 1;
            } 
            else {
                if(mp[s].second - i == 0) {
                    continue;
                }
                else {
                    cout << "YES\n";
                    goto last;
                }
            }
        }
        cout << "NO\n";
        last:;
    }
}