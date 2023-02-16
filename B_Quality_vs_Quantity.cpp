#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), [](auto it1, auto it2){return it1 > it2;});

        vector<int> prefixSUm(n + 1);
        for(int i = 0; i < n; i++){
            prefixSUm[i+1] = prefixSUm[i] + a[i];
        }

        int ans = 0, i = 1;
        int y = n/2 + ((n % 2 == 0) ? (-1) : 0 );
        bool flag = true;
        while(i <= y){
            if(prefixSUm[i] > (prefixSUm[n] - prefixSUm[ n -i - 1])){
                
                cout <<"YES\n";
                flag = false;
                break;
            }
            i++;
        }
        if(flag){
            cout <<"NO\n";
        }
    }
}