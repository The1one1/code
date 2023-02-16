#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int p; cin >> p;
        int x = p/100;
        x += p%100;

        if(x > 10){
            cout << -1 <<"\n";
        }
        else cout << x << endl;
    }
}