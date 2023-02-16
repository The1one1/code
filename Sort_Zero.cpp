#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

int fun(vector<int> &a) {
	int n = a.size();
	for (int i = n - 1; i > 0; i--) {
		if (a[i] - a[i - 1] < 0) {
			return i - 1;
		}
	}
	return -1;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int ind = fun(a);
		set<int> s;
		for (int i = 0; i <= ind; i++) {
			s.insert(a[i]);
		}
		// cout <<" = "<< ind << endl;
		cout << s.size() << endl;
	}
}