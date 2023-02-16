#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> arr(n + 1);
		iota(arr.begin(), arr.end(), 0);
		int value = (int)pow(2, (int)(log2(n) + 1));

		if ((n == 2 and x != 3) or (n & (n - 1) == 0 and (n & x == 0)) or (x >= value)) {
			cout << "-1\n";
		}
		else if (n == 2) {
			cout << "1 1 2" << endl;
		}
		else {
			int y = 3;
			int i = 4;
			while (i <= n) {
				if ((i & (i - 1)) != 0) {
					cout << 1 << " " << y << " " << i << endl;
					y = (y bitor i);
				}
				i++;
			}

			for (int i = 0; i < (int)(log2(n) + 1); i++) {
				int ans = (1ll << i);
				if ((x & ans) == 0) {
					cout << "2 " << y << " " << ans << endl;
					y = (y xor ans);
				}
				else {
					cout << "1 " << y << " " << ans << endl;
					y = (y bitor ans);
				}
			}
		}
	}
}