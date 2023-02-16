#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;  // m = sum, n = number of elements
        vector<int> v(n);
        if(n > m) {
            cout << "NO\n";
            continue;
        }
        if(n % 2 == 0) {
            if(m % 2 == 1)
                cout << "No" << endl;
            else {
                cout << "Yes" << endl;
                for(int i = 0; i < n - 2; i++) {
                    cout << 1 << " ";
                    m--;
                }
                cout << m / 2 << " " << m / 2 << endl;
            }
        }
        else if(n % 2 == 1) {        
            cout << "YES" << endl;
            for(int i = 0; i < n - 1; i++) {
                cout << 1 << " ";
                m--;
            }
            cout << m << endl;
            
        }
    }
}