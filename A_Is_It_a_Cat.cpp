#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        for(auto &it: str) {
            it = tolower(it);
        }

        // resize the string
        str.resize(distance(str.begin(), unique(str.begin(), str.end())));

        if(str.size() != 4) {
            cout << "NO\n";
            continue;
        }

        string s = "meow";
        int j = 0;

        for(int i = 0; i < str.size(); i++) {
            if(j < 4 and str[i] == s[j]) {
                j++;
            }
        }

        if(j == 4) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
}