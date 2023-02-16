#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string num; cin >> num;
            
        int x = (int)(num[0] - '0');
        if(x != 9) {
            vector<int> v(n, 9);
            for(int i = n - 1; i >= 0; i--) {
                v[i] = v[i] - (int)(num[i] - '0');
            }
            for(auto &it: v) {
                cout << it ;
            }cout << endl;
        }
        else {
            vector<int> v(n+1, 1);
            for(int i = n; i > 0; i--) {
                int y = (int)(num[i-1] - '0');
                if(v[i] >= y) {
                    v[i] = v[i] - y;
                }
                else {
                    v[i-1]--;
                    v[i] = 10 + v[i] - y;
                }
            }

            for(int i = 1; i <=n; i++) {
                cout << v[i];
            }cout << endl;
        }
    }
}