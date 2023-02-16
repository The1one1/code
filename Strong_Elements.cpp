#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> prefixGcd(n+1), suffixGcd(n+1);
        prefixGcd[0] = suffixGcd[n] = 0;
        for(int i = 1; i <= n; i++) {
            prefixGcd[i] = __gcd(prefixGcd[i-1], a[i-1]);
        }
        for(int i = n-1; i >= 0; i--) {
            suffixGcd[i] = __gcd(suffixGcd[i+1], a[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(__gcd(prefixGcd[i-1], suffixGcd[i]) != 1) ans++;
        }
        cout << ans << endl;
    }
}