class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        string ans;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(st.empty() and s[i] != '*') {
                ans += s[i];
            }
            else if(s[i] == '*') {
                st.push(i);
            }
            else if(!st.empty() and s[i] != '*'){
                ST.pop();
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};