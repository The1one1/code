#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		int sum = 0;
		for (int i = 1; i < n; i++) {
			int x = abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]);

			int y = abs(a[i - 1] - b[i]) + abs(b[i - 1] - a[i]);

			if ( x <= y) {
				sum += x;
			}
			else {
				swap(a[i], b[i]);
				sum += y;
			}
		}

		cout << sum << endl;
	}
}