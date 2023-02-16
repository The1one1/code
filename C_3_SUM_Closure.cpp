#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a;
        unordered_map<int, int> m;
        int ZeroCnt  = 0; 
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x == 0) ZeroCnt++;
            else a.push_back(x);
        }

        if(ZeroCnt == n) {
            cout <<"YES\n";
            continue;
        }
        int i = 2;
        while(ZeroCnt > 0 and i > 0) {
            a.push_back(0);
            ZeroCnt--;
            m[0]++;
            i--;
        }

        if(a.size() >= 7 - i) {
            cout << "NO\n";
            continue;
        }
        
        for(auto &it: a){
            if(m[it] == 0) m[it]++;
        }
        
        for(int i = 0; i < a.size(); i++)  {
            for(int j = i + 1; j < a.size(); j++) {
                for(int k = j + 1; k < a.size(); k++) {
                    if(m.find(a[i] + a[j] + a[k]) == m.end()) {
                        cout << "NO\n";
                        goto end;
                    }
                }
            }
        }
        cout << "YES\n";
        end:;
    }
}