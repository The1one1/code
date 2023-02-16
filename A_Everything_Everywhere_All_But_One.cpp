#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }

        for(int i = 0; i < n; i++){
            if((sum - v[i]) % (n-1) == 0 and sum == n * v[i]){
                cout << "Yes\n";
                goto last;
            }
        }
        cout <<"No\n";
        last:;
    }
}