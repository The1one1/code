#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<bitset<25>> odd, even;
    for(int i = 0; i < n; i++) {
        bitset<25> b;
        string str; cin >> str;
        for(auto &it: str) {
            int ind = it - 'a';
            b[ind] = b[ind] ^ 1;
        }

        if(b.count() % 2 == 0) 
            even.push_back(b);
        else 
            odd.push_back(b);
    }

    int cnt = 0;
    for(int i = 0; i < odd.size(); i++) {
        for(int j = 0; j < even.size(); j++) {
            bitset<25> b = odd[i] ^ even[j];
            if(b.count() == 25) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}