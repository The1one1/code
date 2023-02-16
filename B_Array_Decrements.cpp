#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int cnt = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            if(b[i] == 0) cnt++;
        }

        if(cnt == n){
            cout <<"YES\n";
            continue;
        }
        vector<int> c(n);
        int m = 0;
        bool flag = true;
        for(int i = 0; i < n; i++){
            c[i] = a[i] - b[i];
            if(c[i] >= m) m = c[i];
            if(c[i] < 0){
                cout <<"NO\n";
                flag = false;
                break;
            }
        }
        if(flag){
            bool g = true;
            for(int i = 0; i < n; i++)
            {
                if(c[i] == m) continue;
                if(c[i] < m and b[i] != 0) {
                    cout <<"NO\n";
                    g = false;
                    break;
                }
            }
            if(g){
                cout <<"YES\n";
            }
        }
    }
}