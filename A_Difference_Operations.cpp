#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        if(arr[0] == 1) {
            cout << "YES\n";
            continue;
        }
        else {
            for(int i = 1; i < n; i++) {
                if(arr[i] % arr[0] == 0) {
                    continue;
                }
                cout << "NO\n";
                goto last;
            }
        }
        cout << "YES\n";
        last:;
    }
}