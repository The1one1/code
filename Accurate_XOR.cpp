// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<vector<int>> adj;
// vector<bool> bit;

// bool dfs(int node, int &k) {
//     if(adj[node].size() == 0){
//         if(k > 0) bit[node] = 1, k--;
//         return bit[node];
//     }
// it(vector<int> &p)
// //     {
//     for(auto &child: adj[node]) {
//         flag xor_eq dfs(child, k);
//     }

//     bit[node] = flag xor (k != 0); 
//     k -= (k != 0);
//     return (k != 0);
// }

// signed main(){
//     int t; cin >> t;
//      while(t--) {
//         int n, k; cin >> n >> k;
//         vector<int> par(n-1);
//         bit = vector<bool>(n+1);
//         for(auto &it: par) cin >> it;
//         adj = vector<vector<int>> (n+1);
//         for(int i = 1; i < n; i++){
//             adj[par[i-1]].push_back(i+1);
//         }
//         dfs(1, k);
//         for_each(bit.begin() + 1, bit.end(), [&](auto it){ cout << it;});cout << endl;
//      }
// }


#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for(int k = 1; k <= t; k++) {
        int n; cin >> n;
        vector<int> r(n);
        for(auto &it: r) {
            cin >> it;
        }
        
        vector<int> a = r;
        vector<int> ans;
		map<int, int> m;
		for(int i = 0; i < n; i++) {
			m[a[i]]++;
		}

        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            auto x = lower_bound(a.begin(), a.end(), 2*r[i]) - a.begin();
            if(x == n) x--;
            for(int j = x; j >= 0; j--) {
                if(a[j] <= 2*r[i] ) {
					if(a[j] == r[i] and m[a[j]] == 1) {
						continue;
					}
					else {
						ans.push_back(a[j]);
                    	goto last;
					}
                }      
            }   
			ans.push_back(-1);
			last:;
        }
        cout << "Case #"<<k<<": ";
        for(auto it: ans) {
            cout << it <<" ";
        }cout << endl;
    }
}
