#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        string str; cin >> str;
        set<char> s;
        for(auto &it:str) {
            s.insert(it);
        }

        int distinct = s.size();
        int n = str.size();
        bool flag = true;
        for(int i = 0; i < n; i++) {
            map<char, int> m;
            for(int j = i; j < min(n, i + distinct); j++) {
                m[str[j]]++;
                if(m[str[j]] >= 2) {
                    flag = false;
                    goto last;
                }
            }
        }
        if(flag) {
            cout << "YES\n";
        }
        else {
            last:;
            cout << "NO\n";
        }
    }
}