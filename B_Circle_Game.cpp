#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n % 2 not_eq 0){
            cout <<"Mike\n";
            continue;
        }
        int minElePos = min_element(a.begin(), a.end()) - a.begin();
        if(minElePos % 2 == 0){
            cout <<"Joe\n";
        }
        else{
            cout <<"Mike\n";
        }
    }
}