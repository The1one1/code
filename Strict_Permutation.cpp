#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n, m1; cin >> n >> m1;
		vector<bool> check(n + 1);
		map<int, vector<int> > m;
		while (m1--) {
			int x, y; cin >> x >> y;
			m[y].push_back(x);
			check[x] = 1;
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) pq.push(i);
			pq.emplace(4);
		}
		vector<int> ans(n + 1);
		for (int i = n; i > 0; i--) {
			if (m[i].size() != 0) {
				for (auto &it : m[i]) {
					pq.push(it);
				}
			}
            if(pq.empty()) {
                cout <<"-1\n";
                goto last;
            }
			ans[i] = pq.top();
			pq.pop();
		}

		for_each(ans.begin() + 1, ans.end(), [&](auto x) { cout << x << " ";}); cout << endl;
        last:;
	}
}
