#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        int count = 0;
        for(int i = 0; i < 2*n - 1; i++) {
            if(str[i] == '(' && str[i + 1] == '(') {
                count++;
            }
        }
        cout << count + 1 << endl;
    }
}