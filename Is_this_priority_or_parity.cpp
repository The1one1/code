#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(k % 2 == 1){
            if(k == 1){
                if(n%2 == 0) cout <<"Even" << endl;
                else cout << "Odd" << endl;
            }
            else cout << "EVEN" << endl;
        }
        else{
            if(k == 2){
                cout << "Odd" << endl;
            }
            else cout << "EVEN" << endl;
        }
    }
}