#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

class Solution {
public:

    int coinCount(vector<int> & coins, int amount, vector<int> &dp){
        if(amount == 0)  return 0;
        
        if(dp[amount] != 0) return dp[amount];
        int minCnt = INT_MAX-1;
        for(auto &it: coins){
            if(amount - it >= 0){
                minCnt = min(minCnt, 1 + coinCount(coins, amount - it, dp));
            }
        }
        return dp[amount] = minCnt;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        int minCnt = coinCount(coins, amount, dp);

        return (minCnt == INT_MAX-1) ? -1 : minCnt;
    }
};

signed main(){
    #ifndef ONLINE_JUDGE
    inout
    #endif
    int n, amt; cin >> n >> amt;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    Solution obj;
    cout << obj.coinChange(coins, amt);
}