#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        map<char, pair<int, int>> mp;
        mp['L'] = {-1, 0};
        mp['R'] = {1, 0};
        mp['U'] = {0, 1};
        mp['D'] = {0, -1};

        int x = 0, y = 0;
        for(int i = 0; i < n; i++) {
            x += mp[str[i]].first;
            y += mp[str[i]].second;
            if(x == 1 and y == 1) {
                cout << "YES\n";
                goto last;
            }
        }
        cout << "NO\n";
        last:;
    }
}