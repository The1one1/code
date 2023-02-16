class Solution
{
public:
    bool fun(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {

        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                if (i == 0 and j == 0)
                    dp[i % 2][j] = 1;
                else if (i == 0 and j > 0)
                    dp[i % 2][j] = 0;

                else if (i > 0 and j == 0)
                    dp[i % 2][j] = dp[(i - 1) % 2][j] and (s1[(i - 1)] == '*');

                else
                {
                    if (s1[i - 1] == s2[j - 1] or s1[i - 1] == '?')
                        dp[i % 2][j] = dp[(i - 1) % 2][j - 1];

                    else if (s1[i - 1] == '*')
                        dp[i % 2][j] = dp[(i - 1) % 2][j] or dp[i % 2][j - 1];

                    else
                        dp[i % 2][j] = 0;
                }
            }
        }
        return dp[s1.size() % 2][s2.size()];
    }

    bool isMatch(string &s, string &p)
    {
        vector<vector<int>> dp(2, vector<int>(s.size() + 1, -1));
        return fun(p, s, p.size() - 1, s.size() - 1, dp);
    }
};