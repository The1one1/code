#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x%10]++;
        }

        for(auto &it: m){
            int digit = it.first;
            int digitCnt = it.second;

            for(int i = 1; i <= min((int)3, digitCnt); i++){
                v.push_back(digit);
            }
        }

        int sum = 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                for(int k = j + 1; k < v.size(); k++){
                    sum = (v[i] + v[j] + v[k]);
                    if(sum % 10 == 3){
                        cout << "YES\n";
                        goto last;
                    }
                }
            }
        }

        cout << "NO\n";
        last:;
    }
}