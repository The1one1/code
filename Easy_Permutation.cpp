#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = n; i >= 1; i--) {
            cout << i << " ";
        }
        cout << endl;
    }
}