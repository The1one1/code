
// ! tabulation

class Solution
{
public:
    int minOpt(string &str1, string &str2, int n, int m, vector<vector<int>> &dp)
    {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0) dp[i][j] = j;
                else  if( j == 0) dp[i][j] = i;
                else if(str1[i-1] != str2[j-1]){
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
                else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        return minOpt(word1, word2, word1.size(), word2.size(), dp);
    }
};



// ! recursive approach


class Solution
{
public:
    int minOpt(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != 0)
            return dp[i][j];

        if (str1[i] == str2[j])
            return dp[i][j] = minOpt(str1, str2, i - 1, j - 1, dp);
        else
        {
            int x = 1 + minOpt(str1, str2, i, j - 1, dp);
            x = min(x, 1 + minOpt(str1, str2, i - 1, j - 1, dp));
            x = min(x, 1 + minOpt(str1, str2, i - 1, j, dp));
            return dp[i][j] = x;
        }
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size()));
        return minOpt(word1, word2, word1.size() - 1, word2.size() - 1, dp);
    }
};