#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (auto &it : a) {
			cin >> it;
		}

		sort(a.begin(), a.end());
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			int nEle = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
			if (nEle > n - nEle) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}