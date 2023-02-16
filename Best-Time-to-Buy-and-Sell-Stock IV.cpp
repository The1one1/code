class Solution
{
public:
    int maxProfit(int k, vector<int> &price)
    {
        int n = price.size();
        vector<vector<int>> ahead(k + 1, vector<int>(3, 0));
        vector<vector<int>> curr(k + 1, vector<int>(3, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap < 3; cap++)
                {
                    if (buy)
                    {
                        curr[buy][cap] = max(-price[idx] + ahead[0][cap], ahead[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] = max(price[idx] + ahead[1][cap - 1], ahead[0][cap]);
                    }
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};