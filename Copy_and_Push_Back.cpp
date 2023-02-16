#include<bits/stdc++.h>
using namespace std;
#define int long long

bool isequal(string str1, string str2) {
    return (str1 == str2);
}

signed main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string str; cin >> str;
        bool flag = true;

        while(n > 0) {
            if(n % 2 == 0) {
                if(isequal(str.substr(0, n/2), str.substr(n/2, n/2))) 
                    n = n/2;
                else {
                    flag = false;
                    break;
                }
            }
            else {
                n--;
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
}