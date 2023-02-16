#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin  >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;

        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                for(int k = 1; k <= 10; k++) {
                    if(min(i,j) == a and min(j, k) == b and min(k, i) == c) {
                        cout <<"YES\n";
                        goto last;
                    }
                }
            }
        }
        cout << "NO\n";
        last:;
    }
}