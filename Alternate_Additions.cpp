#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin>> a >> b;
        int x = (b - a)%3;
        int y = (b - a - 1) % 3;
        if(x == 0 or y == 0){
            cout << "YES\n";
        }
        else cout <<"NO\n";
    }
}