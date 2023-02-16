#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        int cnt = 0, maxCnt = 0, ele = 0, maxEle = 0;
        for(auto &it: m) {
            maxCnt = max(it.second, maxCnt);
            maxEle = max(maxEle, it.first);
            if(it.second == 1) {
                cnt++;
                ele = it.first;
            }
        }
        if(cnt == 1 and ele < maxEle){
            cout << 1 <<"\n";
        }
        else if(cnt == 1 and ele == maxEle){
            if(maxCnt > 2) cout << "1\n";
            else cout << "2\n";
        }
        else if(cnt % 2 == 0){
            cout << cnt/2 << endl;
        }
        else cout << cnt/2 + 1 << endl;
    }
}