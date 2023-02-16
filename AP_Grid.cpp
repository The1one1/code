#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

void fun(vector<int> &a){
    int n = a.size();
    int d = 1;
    for(int i = 0; i < n; i++){
        a[i] = d;
        d += 2;
    }
}

signed main(){
    vector<int> a((int)1e5);
    fun(a);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int d = -1, x = 0;
        for(int i = 0; i < n; i++){
            int y = a[i];
            cout << y <<" ";
            d += 2;
            for(int j = 1; j < m; j++){
                cout << y + d << " ";
                y = y + d;
            }
            cout << endl;
        }
    }
}