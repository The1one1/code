#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int cnt = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                int x; cin >> x;
                if(x == 1) cnt++;
            }
        }
        if(cnt == 0) cout << 0 <<endl;
        else if( cnt == 1 or cnt == 2 or cnt == 3) cout << 1 << endl;
        else cout << 2 << endl;
    }
}