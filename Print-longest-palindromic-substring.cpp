class Solution
{
public:
    string lcs(string &str1, string &str2, vector<vector<string> > &dp)
    {
        for(int i = 1; i <= str1.size(); i++){
            for(int j = 1; j <= str2.size(); j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1] + str1[i-1];
                }
                else{
                    dp[i%2][j] = (dp[(i-1)%2][j].size() >  dp[i%2][j-1].size() )? dp[(i-1)%2][j] : dp[i%2][j-1];
                }
            }
        }
        return dp[str1.size()%2][str2.size()];
    }

    string longestPalindrome((string &text1)
    {
        string text2;
        for(int i = text1.size() - 1; i >= 0; i--){
            text2.push_back(text1[i]);
        }
        vector<vector<string>> dp(2, vector<string>(text2.size()+1, ""));
        return lcs(text1, text2, dp);
    }
};