#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        string str1, str2; cin >> str1 >> str2;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i < n; i++) {
            if(str1[i-1] != str1[i]) continue;
            cnt1++;
        }

        for(int i = 1; i < m; i++) {
            if(str2[i-1] != str2[i]) continue;
            cnt2++;
        }
        if(cnt1 == 0 and cnt2 == 0) {
            cout << "YES\n";
        }
        else if(cnt1 > 1 or cnt2 > 1) {
            cout << "NO\n";
        }
        else if((cnt1 == 0 or cnt2 == 0) and (str1.back() != str2.back())) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}