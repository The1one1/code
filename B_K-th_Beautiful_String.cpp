#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n + 2);
        for(int i = 1; i < n + 2; i++) {
            v[i] = i + v[i - 1];
        }

        int ind = lower_bound(v.begin(), v.end(), k) - v.begin();
        int x = ind - 1;
        int y = k - (x * (x + 1)) / 2;

        string str = string(n, 'a');
        str[n - ind - 1] = 'b';
        str[n - y] = 'b';

        cout << str << endl;
    }
}