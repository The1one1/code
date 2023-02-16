class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
        vector<int> cnt(nums.size(), 1), dp(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(1 + dp[j], dp[i]);
                    if(dp[i] == dp[j] + 1){
                        cnt[i] += cnt[j];
                    }
                    else cnt[i] = cnt[j];
                }
            }
        }

        auto it = max_element(dp.rbegin(), dp.rend()) - dp.rbegin();
        cout << cnt[it] << endl;
        return 1;
    }
};