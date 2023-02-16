#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        deque<int> q;
        int t = 9;
        while(n > 0) {
            if(n >= t) {
                q.push_front(t);
                n = n - t;
                t--;
            }
            else  if(n != 0 and t >= 1) {
                q.push_front(n);
                n = n - n;
            }
        }

        for(auto &it: q) {
            cout << it;
        }cout << endl;
    }
}