#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

long long solve(int n, int k) {
    vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i] - i;
	}

	long long answer = 1;
	for (int i = 0; i < k; i++) {
		answer += upper_bound(b.begin(), b.end(), answer) - b.begin();
    }
	return answer;
}

int main() {
	int t; cin >> t;
    while(t--) 
    {
		int n, k; 
        cin >> n >> k;
        a = vector<long long>(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << solve(n, k) << '\n';
	}
}