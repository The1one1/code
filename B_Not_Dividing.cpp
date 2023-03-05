#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) {
                a[i]++;
            }
        }
        for(int i = 1; i < n; i++) {
            while(a[i] % a[i - 1] == 0) {
                a[i]++;
            }
        }
        for_each(a.begin(), a.end(), [&](auto it){ cout << it << " ";});cout << endl;    
    }
}