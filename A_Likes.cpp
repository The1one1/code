#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int pos = 0, neg = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x < 0) neg++;
            else pos++;
        }
        int pos1 = pos, neg1 = neg;
        // max voting
        int i = 1;
        while(i <= pos) {
            cout << i <<" " ;
            i++;
        }
        while(i <= n) {
            cout << --pos <<" ";
            i++;
        }
        cout << endl;

        // min voting
        i = 1;
        pos = pos1, neg = neg1;
        while(pos > 0 and neg > 0) {
            cout << 1 <<" " << 0 <<" ";
            pos--;
            neg--;
        }

        while(pos > 0) {
            cout << i <<" ";
            i++;
            pos--;
        }
        while(neg > 0) {
            cout << 0 << " ";
            neg--;
        }
        cout << endl;
    }
}