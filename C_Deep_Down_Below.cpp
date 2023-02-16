#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, vector<pair<int, int>> v) {
    int n = v.size();
    for(int i = 0; i < n; i++) {
        if(v[i].first <= mid) {
            mid = mid + v[i].second;
        }
        else return false;
    }
    return true;
}

int bs(int low, int high, vector<pair<int, int>> v) {

    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(check(mid, v))
            high = mid;
        else 
            low = mid;
    }
    if(check(low, v)) return low;
    return high;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++) {
            int _max = 0, b, x; cin >> x;
            for(int j = 0; j < x; j++) {
                cin >> b;
                _max = max(_max, (b - j + 1));
            }
            v.push_back({_max, x});
        }

        sort(v.begin(), v.end());
        
        int low = v[0].first, high = v[n - 1].first;
        cout << bs(low, high,  v) << endl;
    }
}