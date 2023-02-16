#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;

		int rem = k % 4;
		if (not rem) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (rem == 1 or rem == 3) {
			for (int i = 1; i <= n; i += 2) {
				cout << i << " " << i + 1 << endl;
			}
		}
		else {
			for (int i = 1; i <= n; i += 2) {
				if ((i + 1) % 4 != 0) {
					cout << i + 1 << " " << i << endl;
				}
				else {
					cout << i << " " << i + 1 << endl;
				}
			}
		}
	}
}