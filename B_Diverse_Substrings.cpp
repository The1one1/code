#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<char, int> freq;
            int maxFreq = 0, distNum = 0;
            for(int j = i; j < min(n, i + 100); j++) {
                freq[s[j]]++;
                maxFreq = max(maxFreq, freq[s[j]]);
                distNum = freq.size();
                if(maxFreq <= distNum) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}