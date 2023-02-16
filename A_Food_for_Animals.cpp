#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
        x = x - a;
        if(x > 0) c = c- x;
        y = y - b;
        if(y > 0) c = c - y;
        if(c >= 0) {
            cout <<"YES\n";
        }
        else cout << "NO\n";
    }
}