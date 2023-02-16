#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        if(target.size() > s.size()) return 0;
        unordered_map<char, int> m1, m2;        
        for(int i = 0; i < s.size(); i++){
            m1[s[i]]++;
        }

        for(int i = 0; i < target.size(); i++){
            m2[target[i]]++;
        }

        int ans = INT_MAX;

        for(int i = 0; i < target.size(); i++){
            ans = min(ans, m1[target[i]]/m2[target[i]]);
        }
        return ans;
    }
};