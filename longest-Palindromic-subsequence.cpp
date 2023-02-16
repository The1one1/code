class Solution {
public:

    int lcs(string &str1, string &str2, vector<vector<int>> &dp)
    {
        for(int i = 1; i <= str1.size(); i++){
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
                }
                else{
                    dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
                }
            }
        }
        return dp[str1.size()%2][str2.size()];
    }

    int longestPalindromeSubseq(string s) {
        string str = s.reverse();

        vector<vector<int>> dp(2, vector<int>(text2.size(), 0));
        return lcs(s, str2, dp);
    }
};