#include<bits/stdc++.h>
using namespace std;
#define int long long

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        set<int> s;
        for (int i = 1; i <= n; i++) {
            if (a[i] > 9) {
                s.insert(i);
            }
        }

        while (q--) {
            int x; cin >> x;
            if (x == 1) {
                int l, r; cin >> l >> r;
                auto x = s.lower_bound(l);
                vector<int> v;
                while (x not_eq s.end() and *x <= r) {
                    a[*x] = digitSum(a[*x]);
                    auto y = x;
                    if (a[*x] <= 9) {
                        v.push_back(*x);
                    }
                    x++;
                }
                for (auto i : v) {
                    s.erase(i);
                }
            }
            else {
                int l; cin >> l;
                cout << a[l] << endl;
            }
        }
    }
}