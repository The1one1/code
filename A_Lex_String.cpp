#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string a, b, c; cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int x = k, y = k;
        int i = 0, j = 0;
        while(i < n and j < m){
            if(a[i] < b[j] and x > 0){
                c.push_back(a[i]);
                i++;
                x--;
                y = k;
            }
            else if(y > 0){
                c.push_back(b[j]);
                j++;
                y--;
                x = k;
            }
            else{
                c.push_back(a[i]);
                i++;
                x--;
                y = k;
            }
        }
        cout << c << endl;
    }
}