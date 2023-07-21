#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, w, h; cin >> n >> w >> h;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = a[i] - w;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            b[i] = b[i] - h;
        }
        int MinInc = b[0] - a[0];
        for(int i = 0; i < n; i++) {
            a[i] = a[i] + MinInc;
        }

        MinInc = (a[0] + 2*w) - (b[0] + 2*h);
        for(int i = 1; i < n; i++) {
            if((b[i] + 2*h) > (a[i] + 2*w)) {
                cout<< "NO" << endl;
                goto last;
            }
            MinInc = min(MinInc, (a[i] + 2*w) - (b[i] + 2*h));
        }

        for(int i = 0; i < n; i++) {
            if(a[i] > b[i]) {
                if(a[i] - b[i] > MinInc) {
                    cout << "NO" << endl;
                    goto last;
                }
            }
        }

        cout << "YES\n";
        last:;

    }
}