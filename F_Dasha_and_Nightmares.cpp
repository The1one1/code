#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        bitset<25> b;
        set<char> s;
        string str; cin >> str;
        for(auto &it: str) {
            int ind = it - 'a';
            b[ind] = b[ind] ^ 1;
            s.insert(it);
        }
        v.push_back({s.size(), b.to_ullong()});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    vector<int> newArr(n);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << "  " << v[i].second << endl;
        newArr[i] = v[i].first;
    }
    for(int i = 0; i < n; i++) {
        int ind = lower_bound(newArr.begin() + i + 1, newArr.end(), (25 - v[i].first)) - newArr.begin();
        while(ind < n and v[ind].first == (25 - v[i].first)) {
            bitset<25> bits = (v[i].second ^ v[ind].second);
            if(bits.count() == 25) {
                ans++;
            }
            ind++;
        }
    }
    cout << ans << endl;
}



/*
int bitmask = (1 << 26) - 1;
    map<int, int> mp;
    for(auto &it: v) {
        mp[it.to_ullong()]++;
    }
    for(auto it: mp) {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
    int ans = 0;

    for(auto &it: v) {
        int x = it.to_ullong();
        for(int i = 0; i < 26; i++) {
            ans += mp[bitmask - x - (1 << i)];
        }
    }
*/