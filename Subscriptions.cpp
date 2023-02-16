#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        cout << x*(n/6 + ((n%6 != 0) ? 1 : 0)) << endl;
    }
}