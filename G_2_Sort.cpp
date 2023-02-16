#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int length = 1, cnt = 0;
        for(int j = 1; j < n; j++){
            if(a[j-1] < 2 * a[j]){
                length++;
            }
            if(length == k+1){
                cnt++;
                length--;
            }
            if(a[j-1] >= 2 * a[j]){
                length = 1;
            }
        }
        cout << cnt << endl;
    }
}