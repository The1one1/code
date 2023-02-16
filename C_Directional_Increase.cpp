#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if(sum != 0 or a.back() > 0 or a[0] < 0){
            cout << "NO\n";
        }
        else
        {
            int y = 0;
            for(int i = 0; i < n; i++)
            {
                y = a[i] + y;
                if(y == 0)
                {
                    for(int j = i+1; j < n; j++){
                        if(a[j] != 0){
                            goto last;
                        }
                    }
                    goto first;
                }
                if(y < 0){
                    goto last;
                }
            }
            if(y == 0){
                first:;
                cout <<"YES\n";
            }
            else {
                last:;
                cout <<"NO\n";
            }
        }
    }
}