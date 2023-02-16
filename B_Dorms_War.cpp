#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string str; cin >> str;
		int k; cin >> k;
		vector<int> v(26);
		for (int i = 0; i < k; i++) {
			char x; cin >> x;
			v[(int)(x-'a')]++;
		}

		int ans = 0, cnt = 0;
		bool flag = false;
		for (int i = n - 1; i >= 0; i--) {
			if (v[(int)(str[i] - 'a')] == 0 and flag) {
				cnt++;
			}
			else if (v[(int)(str[i]-'a')] != 0) {
				if (cnt != 0) {
					cnt++;
				}
				else if (cnt == 0 and i != 0) {
					cnt = 1;
				}
				ans = max(ans, cnt);
				flag = true;
				cnt = 0;
			}
		}
		cout << max(cnt, ans) << endl;
	}
}