#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(string &str, string &s) {
    return (s.find(str) != string::npos);
}

signed main(){
    int t; cin>> t;
    while(t--) {
        string s, t; cin >> s >> t;


        for(int i = 0; i < t.size(); i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 and r < t.size()) {
                if(t[l] == t[r]) {
                    l--, r++;
                }
                else break;
            }
            
            if(l != -1 and r != t.size() ) continue;

            string str = "";
            if(l == -1) {
                str = t.substr(i);
                reverse(str.begin(), str.end());
            }
            else if(r == t.size()){
                str = t.substr(0, i + 1);
            }

            // if(check(str, s)) {
            if((s.find(str) != string::npos)) {
                cout << "YES\n";
                goto last;
            }
        }

        cout << "NO\n";
        last:;
    }
}