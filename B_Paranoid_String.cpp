#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int ans = n;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i-1]){
                ans += i;
            }
        }
        cout << ans << endl;
    }
}