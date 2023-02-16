#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

bool check(int n, int mid, map<int, int> &m) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int value = m[i];
		// cout << "i=" << i << " " << m[i] << " mid = " << mid << endl;
		if (mid > value)
			cnt += (mid - value) / 2;

		else if ( mid < value)
			cnt -= (value - mid);
	}
	// cout << "cnt=" << cnt << endl;
	return cnt >= 0;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> arr(m);
		map<int , int> fre;
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
			fre[arr[i]]++;
		}

		int low = 1, high = 2 * m;
		while (high - low > 1) {
			int mid = (high + low) / 2;
			if (check(n, mid, fre))
				high = mid;
			else
				low = mid + 1;
		}

		if (check(n, low, fre)) cout << low << endl;
		else cout << high << endl;
	}
}