#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, vector<int> &a, vector<pair<int, int>> &p, int n) {
    vector<int> temp(n + 1, 0);
    for(int i = 0; i <= mid; i++) {
        temp[a[i]] = 1;
    }

    for(int i = 1; i <= n; i++) {
        temp[i] += temp[i - 1];
    }

    for(auto x : p) {
        if(temp[x.second] - temp[x.first - 1] >= ((x.second - x.first + 1) / 2 + 1)) {
            return true;
        }
    }
    return false;
}

int Bsearch(vector<int> &a, vector<pair<int, int>> &p, int n) {
    
    int low = 0, high = a.size() - 1;
    while(high - low > 1) {
        int mid = (low + high) / 2;

        if(check(mid, a, p, n)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if(check(low, a, p, n)) {
        return low + 1;
    } else if(check(high, a, p, n)) {
        return high + 1;
    } else {
        return -1;
    }
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;

        vector<pair<int, int>> p;
        while(m--) {
            int x, y; cin >> x >> y;
            p.push_back({x, y});
        }

        int q; cin >> q;
        vector<int> a(q);
        for(int i = 0; i < q; i++) {
            cin >> a[i];
        }

        cout << Bsearch(a, p, n) << endl;
    }
}