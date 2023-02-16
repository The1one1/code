#include<bits/stdc++.h>
using namespace std;
#define int long long
int l = 0;

auto binary_fun(vector<int> &h, int &c, int &j, int k) {
    int low = 0, high = h.size() - 1;
    while(high - low > 1) {
        int mid = (high + low) / 2;
        if(h[mid] + c > k*j) {
            high = mid;
        }
        else low = mid;
    }
    if(h[low] + c > k*j) {
        l = low;
        return low;
    }
    else {
        l = high;
        return high;
    }
}

void binarySearch(vector<int> &h, vector<int> &suffMin, int &c, int &j, int k) {
    auto ind = binary_fun(h, c, j, k);
    if(ind != h.size()) {
        c += suffMin[ind];
    }
    j++;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> h(n), p(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        for(int i = 0; i < n; i++) cin >> p[i];

        vector<pair<int, int> > vp;
        for(int i = 0; i < n; i++) {
            vp.push_back({h[i], p[i]});
        }
        sort(vp.begin(), vp.end());
        vector<int> suffMin;  // suffix minimum
        for(int i = 0; i < n; i++) {
            suffMin.push_back(vp[i].second);
            h[i] = vp[i].first;
        }
        p.clear(), vp.clear();

        for(int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i], suffMin[i + 1]);
        }

        int maxEle = h.back(), c = 0, j = 1;
        while(maxEle + c > k * j) {
            int x = (maxEle + c - k * j);
            binarySearch(h, suffMin, c, j, k);
            if(x == (maxEle + c - k * j) or l == h.size()) {
                break;
            }
        }
        if(maxEle + c <= k * j) cout << "YES\n";
        else cout << "NO\n";
    }
}