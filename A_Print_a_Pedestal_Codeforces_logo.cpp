#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x = (n+3)/3;
        
        if((n+3)%3 == 1){
            cout << x-1<<" "<<x+1<<" "<<x-2<<endl;
        }
        else if((n+3)%3 == 2){
            cout << x <<" "<<x+1<<" "<<x-2<<endl;
        }

        else{
            cout << x-1 <<" "<<x<<" "<<x-2<<endl;
        }
    
    }
}