#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n+1);
        a[n-1] = 1, a[n] = n;
        bool flag = false;
        for(int i = n-2; i > 0; i--){
            if(flag){
                a[i] = abs(a[i+1] - i);
                flag = false;
            }
            else{
                a[i] = abs(a[i+1] + i);
                flag = true;
            }
        }
        for(int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }cout << endl;
    }
}