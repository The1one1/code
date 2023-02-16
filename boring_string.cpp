#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    string str; cin >> str;
	    map<char, vector<int>> m;
	   
	    str.push_back('_');
	    for(int i = 0; i < 26; i++) {
	        char x = 'a' + i;
	        int len = 0;
	        for(int i = 0; i < str.size(); i++) {
	            if(str[i] == x) {
	                len++;
	            }
	            else if(len != 0){
	                m[x].push_back(len);
	                len = 0;
	            }
	        }
	    }
	    
	    int ans = 0;
	    for(auto &it: m) {
	        vector<int> v = it.second;
	        sort(v.begin(), v.end(), [](auto x, auto y){return x > y;});
	        if(v.size() > 1 and v[0] == v[1]) {
	            ans =max(ans, v[0]);
	        }
	        else {
	            ans = max(ans, v[0] - 1);
	        }
	    }
	    cout << ans << endl;
	}
}