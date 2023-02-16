#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l2 <= l1 and l1 <= r2){
            cout << l1 << endl;
        }
        else if(l1 <= l2 and l2 <= r1){
            cout << l2 << endl;
        }
        if(r1 < l2 or r2 < l1){
            cout << l1 + l2 << endl;
        }
    }
}