#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int ind = 2;
        for(int i = 1; i <= n; i++)  {
            if(a[i] % (i + 1) != 0) 
                continue;
            
            ind = i - 1;
            while((ind >= 1) and (a[i] % (ind + 1) == 0)) {
                ind--;
            }
            if(ind < 1) {
                cout << "NO\n";
                goto last;
            }
        }

        cout << "YES\n";
        last:;
    }
}