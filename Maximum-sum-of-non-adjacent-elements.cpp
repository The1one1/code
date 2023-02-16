#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

int maxSum(vector<int> &nums, int i, vector<int> &dp)
{
    if (i >= nums.size())
        return 0;
    if (dp[i] != 0)
        return dp[i];
    return dp[i] = max(nums[i] + maxSum(nums, i + 2, dp), maxSum(nums, i + 1, dp));
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1);
    return maxSum(nums, 0, dp);
}

signed main()
{
#ifndef ONLINE_JUDGE
    inout
#endif
        int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        cout << maximumNonAdjacentSum(v) << endl;
    }
}