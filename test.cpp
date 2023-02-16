#include<bits/stdc++.h>
using namespace std;

int main()  {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>a(n);
		int sum = 0;
		for (auto &it : a) {
			cin >> it;
			sum += it;
		}
		if (sum % 2 == 0) {
			cout << 0 << endl;
		}
		else {
			int ans = 0;
			while (true) {
				for (int i = 0; i < n; i++) {
					if (a[i] % 2 == 0 and (a[i] / 2) % 2 != 0) {
						goto last;
					}
					else if (a[i] % 2 != 0 and (a[i] / 2) % 2 == 0) {
						goto last;
					}
					a[i] = a[i] / 2;
				}
				ans++;
			}
			last:;
			cout << ans + 1 << endl;
		}
	}
}