#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] == a[i + 1]) cnt++;
        }

        if(cnt <= 0) {
            cout << 0 << endl;
        }
        else {
            for(int i = 0; i < n - 1; i++) {
                if(a[i] == a[i + 1]) {
                    cnt--;
                    if(cnt <= 1) {
                        goto last;
                    }
                    if(i  + 2 < n and a[i + 1] == a[i + 2]) {
                        if(i + 3 < n and a[i + 2] == a[i + 3]) {
                            cnt--;
                        }
                    }
                }
            }
        }
    }
}