#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    vector<int> inf_level(n);
	    for(auto &it: inf_level) cin >> it;
	    
	    int sum = 0;
	    vector<int> ans(n);
	    for(int i = 0; i < n; i++) {
            sum = 0;
	        for(int j = i - 1; j >= 0; j--) {
	            if(sum <= inf_level[j]) {
	                ans[i]++;
	            }
	            sum += inf_level[j];
	        }
	        sum = 0;
	        for(int j = i + 1; j < n; j++) {
	            if(sum <= inf_level[j]) {
	                ans[i]++;
	            }
	            sum += inf_level[j];
	        }
	    }
	    
	    for(int i = 0; i < n; i++) {
	        cout << ans[i] <<" ";
	    }cout << endl;
	}
}