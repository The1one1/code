#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 32768;

signed main() {
	int n; cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		int y = a[i];
		int cnt = 15 - ((y == 0) ? 0 : (__builtin_ctz(y)));
		if (y % N == 0) cnt = min(cnt, 0ll);
		for (int j = 1; j <= 15; j++) {
			if (a[i] + j > N) break;
			y = (a[i] + j) % N;
			if (y == 0) {
				cnt = min(cnt, j);
			}
			else {
				cnt = min(cnt, j + 15 - __builtin_ctz(y));
			}
		}
		cout << cnt << " ";
	}
}