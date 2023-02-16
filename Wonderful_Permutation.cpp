#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int cnt = 0;
		for(int i = 0; i < k; i++) {
			if(a[i] > k) {
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}