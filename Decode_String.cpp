#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string str; cin >> str;

		string s;
		for (int i = n - 1; i >= 0; ) {
			if (str[i] == '0') {
				string a;
				a += str[i - 2];
				a += str[i - 1];
				int x = stoi(a);
				// cout << "a= " << a << " x= " << x << endl;
				s.push_back('a' + x - 1);
				i -= 3;
			}
			else {
				int x = str[i] - '0';
				// cout << "s[i]= " << str[i] << " x=" << x << endl;
				s.push_back('a' + x - 1);
				i--;
			}
		}

		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}