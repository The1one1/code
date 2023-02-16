#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		string str; cin >> str;
		map<char, vector<int>> m;

		for (int i = 1; i <= str.size(); i++) {
			m[str[i - 1]].push_back(i);
		}

		int direction = (str[0] < str.back() ? 1 : -1);
		vector<int> ans;
		int i = 0;
		while (i < 26) {
			if (m.find(str[0] + i * direction) != m.end()) {
				for (auto &it : m[str[0] + i * direction]) {
					ans.push_back(it);
					if (it == str.size()) {
						goto last;
					}
				}
			}
			i++;
		}
last:;
		int cost = 0;
		for (int i = 0; i < ans.size() - 1; i++) {
			cost += abs(str[ans[i] - 1] - str[ans[i + 1] - 1]);
		}
		cout << cost << " " << ans.size() << endl;
		for_each(ans.begin(), ans.end(), [&](auto x) { cout << x << " ";}); cout << endl;
	}
}