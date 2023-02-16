#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fun1(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(3);

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); i++)
        {
            dp[i % 3] = max(nums[i] + dp[(i - 2) % 3], dp[(i - 1) % 3]);
        }
        return dp[(nums.size() - 1) % 3];
    }

    int rob(vector<int> &nums)
    {
        vector<int> temp1, temp2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != nums.size() - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        for(auto it: temp1){
            cout << it << " ";
        }cout << endl;

        for(auto it: temp2){
            cout << it << " ";
        }cout << endl;
        
        return max(fun1(temp1), fun1(temp2));
    }
};