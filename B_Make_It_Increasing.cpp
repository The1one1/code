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
        int cnt = 0;
        for(int i = n-2; i >= 0; i--){
            while (a[i] >= a[i + 1]) {
                if(a[i] == 0) {
                    cout <<"-1\n"; 
                    goto end;
                }
                a[i] = a[i] / 2;
                cnt++;
            }
        }

        cout << cnt << "\n";
        end:;
    }
}