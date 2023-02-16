#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long 

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        bool flag = true;
        for(int i = 0; i < 31; i++){
            if( a == b and b == c){
                cout << "YES\n";
                flag = false;
                break;
            }
            int cnt = ((a>>i) & 1 ) + ( (b >> i) & 1) + ((c >> i) & 1);
            
            if (cnt == 1){
                if((a >> i) & 1) a += (1<<i);
                if((b >> i) & 1) b += (1<<i);
                if((c >> i) & 1) c += (1<<i);
            }
            else if(cnt == 2){
                if(!((a >> i) & 1)) a += (1<<i);
                if(!((b >> i) & 1)) b += (1<<i);
                if(!((c >> i) & 1)) c += (1<<i);
            }
            else break;
        }
        if(flag){
            cout <<"NO\n";
        }
    }
}


