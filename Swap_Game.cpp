#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &it : a) {
			cin >> it;
		}
		int firstEle = a[0];
		sort(a.begin(), a.end());
		if (a[0] != firstEle) {
			cout << "Alice\n";
		}
		else {
			cout << "Bob\n";
		}
	}
}