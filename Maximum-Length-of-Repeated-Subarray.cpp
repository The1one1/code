class Solution {
public:

    int lcs(vector<int>& nums1, vector<int>& nums2, vector<int> &dp)
    {
        int maxLen = 0;
        for(int i = 1; i <= nums1.size(); i++)
        {
            for(int j = nums2.size(); j >= 1 ; j--)
            {
                if(nums1[i-1] == nums2[j-1])
                {
                    dp[j] = 1 + dp[j-1];
                    maxLen = max(maxLen, dp[j]);
                }
                else{
                    dp[j] = 0;
                }
            }
        }
        return maxLen;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> dp(nums2.size()+1, 0);
        return lcs(nums1, nums2, dp);
    }
};