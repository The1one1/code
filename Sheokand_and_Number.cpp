#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	vector<int> v;
	for (int i = 0; i <= 30; i++) {
		for (int j = i + 1; j <= 30; j++) {
			if (i != j) {
				v.push_back((1 << i) + (1 << j));
			}
		}
	}
	sort(v.begin(), v.end());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		int ind = lower_bound(v.begin(), v.end(), n) - v.begin();

		if (ind == 0) {
			cout << abs(v[ind] - n) << endl;
			continue;
		}
		if (v[ind] == n) {
			cout << 0 << endl;
		}
		else {
			cout << min(abs(n - v[ind - 1]), abs(n - v[ind])) << endl;
		}
	}
}















// #include<bits/stdc++.h>
// using namespace std;
// #define int unsigned long long

// signed main() {
// 	int t; cin >> t;
// 	while (t--) {
// 		int n; cin >> n;
// 		bitset<40> bits = n;
// 		if (n == 1) {
// 			cout << 2 << endl;
// 			continue;
// 		}
// 		int OneCnt = bits.count();
// 		if ( OneCnt == 2) {
// 			cout << 0 << endl;
// 			continue;
// 		}
// 		if ( OneCnt == 1) {
// 			cout << 1 << endl;
// 			continue;
// 		}
// 		bitset<40> sub;
// 		int cnt = 0;
// 		for (long i = bits.size() - 1; i >= 0; i--) {
// 			if (cnt < 2 and bits[i]) {
// 				sub[i] = 0;
// 				cnt++;
// 			}
// 			else {
// 				sub[i] = bits[i];
// 			}
// 		}
// 		int x = sub.to_ullong();
// 		int i = 1;
// 		while (i < x and bitset<40> {n + i} .count() != 2) {
// 			i++;
// 		}
// 		cout << min(x, i) << endl;
// 	}
// }