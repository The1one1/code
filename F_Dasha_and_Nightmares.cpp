#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<bitset<25>> odd;
    vector<int> even;
    for(int i = 0; i < n; i++) {
        bitset<25> b;
        string str; cin >> str;
        for(auto &it: str) {
            int ind = it - 'a';
            b[ind] = b[ind] ^ 1;
        }

        (b.count() % 2 == 0) ? even.push_back(b.to_ullong()) : odd.push_back(b);
    }

    int cnt = 0;
    sort(even.begin(), even.end());
    for_each(even.begin(), even.end(), [&](auto it){ cout << it << " ";}); cout << endl;
    for(int i = 0; i < odd.size(); i++) {
        bitset<25> b = ((1 << 26) - 1);
        b =  odd[i] ^ b;
        int ind1 = lower_bound(even.begin(), even.end(), b.to_ullong()) - even.begin();
        int ind2 = upper_bound(even.begin(), even.end(), b.to_ullong()) - even.begin();
        if(ind1 != even.size() and even[ind1] == b.to_ullong()) {
            cnt += (ind2 - ind1);
        }
    }
    cout << cnt << endl;
}