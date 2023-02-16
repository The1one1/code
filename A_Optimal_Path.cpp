#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        cout << (m*(m+1))/2 + m*((n*(n+1))/2 - 1) << endl;
    }
}