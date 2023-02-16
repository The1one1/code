#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        int _1_ind = -1;
        for(int i = str.size() - 1; i >= 0; i--) {
            if(str[i] == '1') {
                _1_ind = i;
                break;
            }
        }
        int _0_ind = -1;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '0') {
                _0_ind = i;
                break;
            }
        }
        if(_1_ind == -1) {
            if(_0_ind == -1) {
                cout << str.size() << endl;
            }
            else {
                cout << _0_ind + 1 << endl;
            }
        }
        else {
            if(_0_ind == -1) {
                cout << str.size() - _1_ind << endl;
            }
            else {
                cout << _0_ind -_1_ind + 1 << endl;
            }
        }
    }
}