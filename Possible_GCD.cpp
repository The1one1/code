#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int diff = abs(a-b);

        // calculate factors of diff
        int cnt = 0;
        for(int i = 1; i*i <= diff; i++){
            if(i*i == diff){
                cnt++;
            }
            else if(diff % i == 0){
                cnt += 2;
            }
        }
        cout << cnt << endl;
    }
}