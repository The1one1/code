#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;
        vector<int> v(n);
        int i = 0, temp = k;
        while(i < n and temp > 0) {
            if(k % 2 == (str[i] - '0')) {
                v[i] = 1;
                temp--;
            }
            i++;
        }
        v[n - 1] += temp;
        
        for(int j = 0; j < n; j++) {
            if((k - v[j])%2 == 1)
                cout << (str[j] == '1' ? 0 : 1);
            else 
                cout << str[j];
        }cout << endl;
        
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}