#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;

        map<char, int> m1;
        for(auto i : s) m1[i]++;
        for(auto i : t) {
            if(m1[i] == 0) {
                cout << "NO\n";
                goto end;
            }
            else m1[i]--;
        }

        if((n == 1 or n == 2 or n == 3) ) {
            if(s == t)
                cout << "YES\n";
            else 
                cout << "NO\n";
        }
        
        else if(n == 4) {
            if(s[1] == t[1] and s[2] == t[2]) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else if(n == 5) {
            if(s[2] == t[2]) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
        end:;
    }
}