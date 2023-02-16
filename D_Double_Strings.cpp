#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        map<string, bool> m;
        for(auto &it: arr) {
            m[it] = 1;
        }

        for(auto &str: arr) {
            for(int i = 1; i < str.size(); i++) {
                string str1 = str.substr(0, i);
                string str2 = str.substr(i, str.size() - i);

                if(m.find(str1) != m.end() and m.find(str2) != m.end()){
                    cout << 1;
                    goto last;
                }
            }
            cout << 0;
            last:;
        }
        cout << endl;
    }
}