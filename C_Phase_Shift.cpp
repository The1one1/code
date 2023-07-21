// #include<bits/stdc++.h>
// using namespace std;

// #define int long long

// signed main() {
//     int t; cin >> t;
//     while (t--) {
//         int n; cin >> n;
//         string t; cin >> t;
//         map<char, char> mpt, mps;

//         int i = 0;
//         char ch = 'a';
//         while(i < n) {
//             // cout << "size=" << mps.size() << endl;
//             if(ch == t[i]) {
//                 ch++;
//                 continue;
//             }
//             if(i < n and mpt.find(t[i]) not_eq mpt.end()) {
//                 // cout <<"ch1 = " << ch << " mpt[ch]1 = " << mpt[t[i]] << endl;
//                 ++i; continue;
//             }

//             if(ch <= 'z' and mps.find(ch) not_eq mps.end()) {
//                 // cout <<"ch = " << ch << " mps[ch] = " << mps[ch] << endl;
//                 ch++; continue;
//             }

//             if((i < n and ch <= 'z')and mpt.find(ch) not_eq mpt.end()) {
//                 // cout << "mpt="<< mpt[ch] << " t[i]=" << t[i] << endl;
//                 if(mpt[ch] == t[i]) {
//                     ch++; 
//                     continue;
//                 }
//             }
//             // cout << "ch = " << ch << " t[i] = " << t[i] << " i=" << i << endl;
//             // cout << "ch = " << ch << " t[i] = " << t[i] << " i=" << i << endl;
//             mps[ch] = t[i];
//             mpt[t[i]] = ch;
//             i++;
//             ch = 'a';
//         }

//         for(auto &ch: t) {
//             cout << mpt[ch];
//         }
//         cout << endl;
//     }
// }









#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	int n;
	string t;
	cin >> n;
	cin >> t;
 
	vector<int> edge(26, -1);
	vector<int> redge(26, -1);
	auto get_path_end = [&](int c) {
		int len = 0;
		int cur = c;
		while (edge[cur] != -1)
			len++, cur = edge[cur];
		return make_pair(cur, len);
	};
	vector<int> vec;
	for (auto c : t)
		vec.push_back(c - 'a');
	for (int i = 0; i < n; i++) {
		if (edge[vec[i]] == -1) {
			for (int c = 0; c < 26; c++)
				if (redge[c] == -1) {
					auto [clast, len] = get_path_end(c);
					if (clast != vec[i] || len == 25) {
						edge[vec[i]] = c;
						redge[c] = vec[i];
						break;
					}
				}
		}
		vec[i] = edge[vec[i]];
	}
 
	for (int i = 0; i < n; i++)
		t[i] = vec[i] + 'a';
 
	cout << t << '\n';
}
 
int main() {
	int t = 1; cin >> t;
	while (t--)
		solve();
}