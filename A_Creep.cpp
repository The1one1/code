#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == b){
            while(a > 0){
                cout <<"01";
                a--;
            }
            cout << endl;
        }
        else if(a > b){
            while(b > 0){
                cout << "01";
                a--, b--;
            }
            while(a > 0){
                cout <<"0";
                a--;
            }cout << endl;
        }
        else{
            while(a > 0){
                cout << "10";
                a--,b--;
            }
            while(b > 0){
                cout <<"1";
                b--;
            }cout << endl;
        }
    }
}