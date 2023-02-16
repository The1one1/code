#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n % 2 == 0){
            cout <<"Yes" << endl;
        }
        else{
            if(k == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}