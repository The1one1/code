#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int cnt = 0;
        if(a < b) cnt++;
        if(a < c) cnt++;
        if(a < d) cnt++;
        cout << cnt << endl;
    }

}