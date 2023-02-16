#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] < 0) {
				sum1 += a[i];
			}
			else {
				sum2 += a[i];
			}
		}

		cout << abs(abs(sum1) - abs(sum2)) << endl;
	}
}