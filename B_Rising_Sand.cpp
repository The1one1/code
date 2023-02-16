#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        if(k == 1){
            cout << ((n % 2 == 0) ? (n-2)/2 : n/2) <<"\n";
        }
        else{
            int cnt = 0;
            for(int i = 1; i < n-1; i++){
                if(a[i] > a[i-1] + a[i + 1]){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }
}