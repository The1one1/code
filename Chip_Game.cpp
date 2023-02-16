#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;

		if((n + m - 2) % 2 == 0) {
			cout << "Tonya" << endl;
		}
		else {
			cout << "Burenka\n";
		}
	}
}