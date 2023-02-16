#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        map<int, int> freq;
        for(int i = 0; i < n; i++) {
            freq[a[i]]++;  
        }
        int freqN = -1;
        vector<int > p1(n + 1, 0), p2(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 0) {
                freqN = i;
            }
            else if(freq[i] == 1) {
                p1[i] = i;
            }
        }
    }
}