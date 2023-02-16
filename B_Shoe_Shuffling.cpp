#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        map<int, vector<int> > m;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            m[v[i]].push_back(i);
        }

        for(auto &[key, value]: m){
            if(value.size() == 1){
                cout <<-1 << endl;
                goto end;
            }
        }

        for(auto &[key, value]: m){
            
            for(int i = 1; i < value.size(); i++){
                cout << value[i] + 1 << " ";
            }
            cout << value[0] + 1<<" ";
        }cout << endl;
        end:;
    }
}