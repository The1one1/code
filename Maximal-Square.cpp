class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) 
        {
            for (int j = m - 1; j >= 0; j--) 
            {
                if (i == n - 1 or j == m - 1) 
                {
                    if (matrix[i][j] != '0')
                        dp[i % 2][j] = 1;
                    else 
                        dp[i % 2][j] = 0; 

                    ans = max(ans, dp[i % 2][j]);
                }
                else if (matrix[i][j] != '0')
                {
                    dp[i % 2][j] = min(dp[i % 2][j + 1], min(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j + 1])) + 1;
                    ans = max(ans, dp[i % 2][j]);
                }
                else if (matrix[i][j] == '0') 
                    dp[i % 2][j] = 0;
            }
        }
        return ans * ans;
    }
};