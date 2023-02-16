#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int> &v, int q) {
	int low = 0, high = v.size() - 1;

	while ( high - low > 1) {
		int mid = (low + high) / 2;
		if (v[mid] <= q) low = mid;
		else high = mid;
	}
	if(v[high] <= q) return high;
	if(v[low] <= q) return low;
	return -1;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, q; cin >> n >> q;
		vector<int> a(n);
		map<int, vector<int>> m;
		for (int i = 0; i < n; i++) cin >> a[i];

		int topPlayer = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[topPlayer]) {
				m[i + 1].push_back(i);
				topPlayer = i;
			}
			else {
				m[topPlayer + 1].push_back(i);
			}
		}

		while (q--) {
			int n, q; cin >> n >> q;

			if (m.find(n) == m.end()) {
				cout << 0 << endl;
			}
			else if (q >= a.size()) {
				if(n == topPlayer + 1)  {
					cout << m[n].size() + q - a.size() + 1 << endl;
				}
				else {
					cout << m[n].size() << endl;
				}
			}
			else {
				vector<int> v = m[n];
				int ind = binarySearch(v, q);
				cout << ind + 1 << endl;
			}
		}
	}
}