#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int x, y; cin >> x >> y;
        if(x == y){
            cout << 0 << endl;
        }
        else if(x < y){
            cout << y - x << endl;
        }
        else{
            int z = (x - y)/2; 
            int k = (x - y)%2;
            if(k == 0){
                cout << z << endl;
            }
            else{
                cout << z + 2 << endl;
            }
        }
    }
}