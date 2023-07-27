#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        string str;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                char ch; cin >> ch;
                if(ch != '.') {
                    str += ch;
                }
            }
        }

        cout << str << endl;
    }
}