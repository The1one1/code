#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if( n == 1){
            cout << "-1\n";
            continue;
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 1);
        for(int i = 0; i < n-1; i++){
            if(a[i] == b[i]){
                swap(b[i], b[i+1]);
            }
        }
        if(a[n-1] == b[n-1]){
            swap(b[n-1], b[n-2]);
        }
        if(a == b){
            cout <<"-1\n";
        }
        else{
            for(int i = 0; i < n; i++){
                cout << b[i] << " ";
            }cout << endl;
        }
    }
}