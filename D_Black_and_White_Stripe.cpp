#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<char> c(n);
        for(int i = 0; i < n; i++) cin >> c[i];

        int wcnt = 0, m = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i < (k-1)){
                if(c[i] == 'W'){
                    wcnt++;
                }
            }
            else{
                if(c[i] == 'W') 
                    wcnt++;
                
                m = min(m, wcnt);
                if(c[i-k+1] == 'W'){
                    wcnt--;
                }
            }
        }
        cout << m << endl;
    }
}