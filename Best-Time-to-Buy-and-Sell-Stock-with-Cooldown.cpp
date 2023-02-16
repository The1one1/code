class Solution
{
public:
    int fun(int idx, bool buy, vector<int> &p, vector<vector<int>> &dp)
    {
        if (idx >= p.size())
            return 0;

        if (buy)
            return max(-p[idx] + fun(idx + 1, 0, p, dp), fun(idx + 1, 1, p, dp));
        else
            max(p[idx] + fun(idx + 2, 1, p, dp), fun(idx + 1, 0, p, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return fun(0, 1, p, dp);
    }
};

// class Solution
// {
// public:
//     int maxProfit(vector<int> &p)
//     {
//         vector<vector<int>> dp(p.size() + 2, vector<int>(2, 0));

//         for (int idx = p.size() - 1; idx >= 0; idx--)
//         {
//             dp[idx][0] = max(p[idx] + dp[idx + 2][1], dp[idx + 1][0]);
//             dp[idx][1] = max(-p[idx] + dp[idx + 1][0], dp[idx + 1][1]);
//         }
//         return dp[0][1];
//     }
// };