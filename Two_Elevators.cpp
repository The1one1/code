#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int x = abs(a - 1);
		int y = abs(b - c) + abs(c - 1);

		if (x < y) {
			cout << 1 << endl;
		}
		else if (x > y) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
}