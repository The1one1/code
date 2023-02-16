#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<pair<int, int>> cnt;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt.push_back({x, i});
		}
		sort(cnt.begin(), cnt.end());
		cout << cnt.back().second + 1 << endl;
	}
}