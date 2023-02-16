#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

void fun(int low, int high) {
	while (low < high) {
		cout << low << " " << high << endl;
		low += 3;
		high -= 3;
	}
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << n / 2 + n % 2 << endl;
		if (n % 2 == 0) {
			int low = 1, high = 3 * n;
			fun(low, high);
		}
		else {
			int low = 1, high = 3 * n;
			fun(low, high);
		}
	}
}