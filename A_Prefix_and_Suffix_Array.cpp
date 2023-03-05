#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> s;
        for(int i = 0; i < (2*n-2); i++) {
            string str; cin >> str;
            if(str.size() == n - 1) {
                s.push_back(str);
            }
        }
        reverse(s[0].begin(), s[0].end());
        if(s[0] == s[1]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}