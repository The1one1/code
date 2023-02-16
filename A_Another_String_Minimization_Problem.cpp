#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        string str = "B";
        for(int i = 1; i < m; i++) {
            str.push_back('B');
        }

        for(int i = 0; i < n; i++) {
            a[i] = min(a[i], m - a[i] + 1);
            if(str[a[i] - 1] == 'B') str[a[i] - 1] = 'A';
            else str[m - a[i]] = 'A'; 
        }

        cout << str << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e9 + 7;

signed main(){
    int t; cin >> t;
    while(t--){
    int n;
    }
}