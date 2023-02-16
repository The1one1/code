#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    vector<int> a(n);
        map<int, int> m;
	    for(auto &it: a) {
	        cin >> it;
            m[it]++;
	    }
	    for(auto &it: m) {
            int c = it.second;
            if(ceil(n/2.0) < c) {
                cout <<"NO"<<endl;
                goto last;
            }
        }
        cout <<"YES"<<endl;
        last:;
	}
}
