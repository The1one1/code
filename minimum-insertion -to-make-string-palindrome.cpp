
class Solution
{
public:
    int lcs(string &str1, string &str2, vector<vector<int>> &dp)
    {
        for (int i = 1; i <= str1.size(); i++)
        {
            for (int j = 1; j <= str2.size(); j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                }
                else
                {
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                }
            }
        }
        return dp[str1.size() % 2][str2.size()];
    }

    int minInsertions(string s)
    {

        string str;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            str.push_back(s[i]);
        }

        vector<vector<int>> dp(2, vector<int>(s.size() + 1, 0));
        int x = lcs(s, str, dp);

        cout << "x=" << x << endl;
        if (x == s.size())
            return 0;
        else
            return (s.size() - x);
    }
};