class Solution {
public:

    vector<int> charCnt(string &words) {
        vector<int> v(26, 0);
        for(auto &it: word) {
            v[it- 'a']++;
        }
        return v;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        int ind = 0;
        vector<string > freq(26, INT_MAX);

        for(auto &it: words1) {
            vector<int> w1 = charCnt(it);
            for(int i = 0; i < 26; i++) {
                freq[i] = min(freq[i], w1[i]);
            }
        }

        for(auto &it: words2) {
            vector<int> w1 = charCnt(it);
            
        }
        return v;
    }
};






#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++) cin >> v[i];
            sort(arr.begin(), arr.end(), [&](auto x, auto y) { return x < y;})
        }
}