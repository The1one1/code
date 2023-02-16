#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n);
		p[n - 2] = n - 1;
		p[n - 1] = n;

		for (int i = 1; i <= n - 2; i++) {
			p[i - 1] = i;
		}

		for (int i = n - 3; i > 0; i -= 2) {
			swap(p[i], p[i - 1]);
		}

		for_each(p.begin(), p.end(), [&](auto x) { cout << x << " ";});
		cout << endl;
	}
}