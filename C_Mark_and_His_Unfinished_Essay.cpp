#include<bits/stdc++.h>
using namespace std;
#define int long long

int fun(vector<pair<int, int>> &v1, vector<pair<int, int>> &v2, int &k, int n) {
	int i = v1.size() - 1;
	while (k > n and i > 0) {
		if (k >= v1[i].first and k <= v1[i].second) {
			k = v2[i].second - v1[i].second + k;
		}
		i--;
	}
	return k;
}

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, c, q; cin >> n >> c >> q;
		string str; cin >> str;

		vector<pair<int, int> > v1, v2;
		v1.push_back({1, n});
		v2.push_back({1, n});

		while (c--) {
			int l, r; cin >> l >> r;
			int x = v1.back().second;
			v1.push_back({x + 1, x + r - l + 1});
			v2.push_back({l, r});
		}

		while (q--) {
			int k; cin >> k;
			cout << str[fun(v1, v2, k, n) - 1] << endl;
		}
	}
}