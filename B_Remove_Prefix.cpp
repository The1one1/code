#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        map<int, int> m;
        int i = 0;
        for(i = n-1; i >= 0; i--){
            if(m[v[i]] == 0) {
                m[v[i]]++;
            }
            else break;
        }

        cout << i + 1 << endl;
    }
}