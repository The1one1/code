class Solution
{
public:
    int fun(int idx, bool buy, vector<int> &price, vector<vector<int>> &dp)
    {
        
        for(int i = price.size()-1; i>= 0; i--){
            for(int j = 0; j < 2; j++){
                if(j == 0){
                    dp[i][j] = max(price[idx] + dp[idx + 1][1], dp[idx + 1][0]);
                }
                if(j == 1){
                    dp[i][j] = max(-1 * price[idx] + dp[idx + 1][0], dp[idx + 1][1]);
                }
            }
        }
        return dp[0][0];
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        return fun(0, 1, prices, dp);
    }
};











//! recursive + memoization


// class Solution
// {
// public:
//     int fun(int idx, bool buy, vector<int> &price, vector<vector<int>> &dp)
//     {
//         if (idx == price.size())
//             return 0;

//         if(dp[idx][buy] != -1) return dp[idx][buy];
//         if (buy)
//         {
//             return dp[idx][buy] = max(-1 * price[idx] + fun(idx + 1, 0, price, dp), fun(idx + 1, 1, price, dp));
//         }
//         else
//         {
//             return dp[idx][buy] = max(price[idx] + fun(idx + 1, 1, price, dp), fun(idx + 1, 0, price, dp));
//         }
//     }

//     int maxProfit(vector<int> &prices)
//     {
//         vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
//         return fun(0, 1, prices, dp);
//     }
// };