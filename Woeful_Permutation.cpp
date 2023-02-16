#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		vector<int> a(n);
		iota(a.begin(), a.end(), 1);
		for (int i = n-1; i > 0; i -= 2) {
			swap(a[i], a[i - 1]);
		}
		for_each(a.begin(), a.end(), [&](auto x) { cout << x << " ";}); cout << endl;
	}
}