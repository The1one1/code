#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int a, b, p; cin >> a >> b >> p;
        string str; cin >> str;
        int n = str.size();
        vector<int> cost(n, 0);
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++) {
            int j = i;
            if(str[i] == 'A') {
                while(j < n && str[j] == 'A') j++;
            }
            else if(str[i] == 'B') {
                while(j < n && str[j] == 'B') j++;
            }
            v.push_back({i, (j == n ? j - 1: j)});
            i = j - 1;
        }

        if(v.back().first == v.back().second) v.pop_back();
        int x = 0;
        cost[n - 1] = (str[v.back().first] == 'A' ? a : b);

        for(int i = v.size() - 1; i >= 0; i--) {
            int r = v[i].second;
            int l = v[i].first;
            for(int j = r - 1; j >= l; j--) {
                cost[j] = x + (str[l] == 'A' ? a : b);
            }
            x = cost[l];
        }

        reverse(cost.begin(), cost.end());

        auto it =upper_bound(cost.begin(), cost.end(), p) - cost.begin();
        cout << (it == 0 ? n : n - it + 1) << endl;
    }
}