class Solution {
public:

    int fun(int idx, bool buy, int cap, vector<int> &price, int dp[][2][3]){
        if(cap == 0) return 0;
        if(idx == price.size()) return 0;
        
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        
        if(buy){
            return dp[idx][buy][cap] = max(-price[idx] + fun(idx+1, 0, cap), fun(idx+1, 1, cap));
        }
        else{
            return dp[idx][buy][cap] = max(price[idx] + fun(idx+1, 1, cap-1), fun(idx + 1, 0, cap));
        }
    }
    int maxProfit(vector<int>& prices) {
        int dp[price.size()][2][3] = {-1};
        return fun(0, 1, 2, prices, dp);
    }
};