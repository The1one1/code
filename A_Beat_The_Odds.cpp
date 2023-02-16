#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        int oddCnt = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i]%2 != 0){
                oddCnt++;
            }
        }

        int evenCnt = n - oddCnt;
        cout << min(oddCnt, evenCnt) << endl;
    }
}