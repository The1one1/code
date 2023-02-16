#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<int> a(n);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1) cnt++;
        }
        if(cnt < s){
            cout <<-1 << endl;
            continue;
        }
        if(cnt == s) {
            cout << 0 << endl;
            continue;
        }
        int i = 0, j = 0, sum = 0, lenght = 0;

        bool flag = true;
        while(i <= j and j < n)   
        {
            if(flag){
                sum += a[j];
                flag = false;
            }
            if(sum > s and i < n) {
                sum -= a[i];
                lenght = max(lenght, j - i);
                if(sum <= s){
                    j++;
                    flag = true;
                }
                i++;
            }
            else {
                j++;
                flag = true;
            }
        }
        lenght = max(lenght, j - i);
        cout << n - lenght  << endl;
    }
}