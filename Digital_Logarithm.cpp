#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		
		priority_queue<int> pq1, pq2;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			pq1.push(x);
		}

		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			pq2.push(x);
		}

		int ans = 0;
		while(not pq1.empty()) {
			int x = pq1.top();
			int y = pq2.top();

			if(x == y){
				pq1.pop();
				pq2.pop();
				continue;
			}
			ans++;
			if(x > y) {
				pq1.pop();
				pq1.push(to_string(x).size());
			}
			else {
				pq2.pop();
				pq2.push((int)log10(y) + 1);
			}
		}
		cout << ans << endl;
	}
}