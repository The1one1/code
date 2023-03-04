#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;
        map<char, int> m;
        for(auto &it: s) m[it]++;
        for(auto &it: t) {
            if(m[it] == 0) {
                cout << "NO" << endl;
                goto end;
            }
            m[it]--;
        }
        if(n >= 1 and n <= k) {
            if(t == s) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if(n >= 2*k) {
            cout << "YES" << endl;
        }
        else {
            int ind = (n - k);
            for(int i = ind; i < k; i++) {
                if(s[i] != t[i]) {
                    cout << "NO" << endl;
                    goto end;
                }
            }
            cout << "YES" << endl;
        }
        end:;
    }
}