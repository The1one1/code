#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		for (int i = 1; i * i <= n; i++) {
			int a = i, b = n - i;
			if (n % i == 0) {
				cnt = ++cnt + (a not_eq b);

				int x = n / i, y = n - x;
				if (min(x, y) != min(a, b) and min(x, y) != 0) {
					cnt = ++cnt + (x not_eq y);
				}
			}
		}
		cout << cnt << endl;
	}
}