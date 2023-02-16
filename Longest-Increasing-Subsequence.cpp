#include <bits/stdc++.h>
int fun(int idx, int pre_idx, int arr[], int n, vector<vector<int>> &dp)
{
    if (idx >= n)
        return 0;

    if (dp[idx][pre_idx + 1] != -1)
        return dp[idx][pre_idx + 1];
    if (pre_idx == -1)
    {
        return dp[idx][pre_idx + 1] = max(1 + fun(idx + 1, idx, arr, n, dp), fun(idx + 1, pre_idx, arr, n, dp));
    }
    else if (arr[idx] > arr[pre_idx])
    {
        return dp[idx][pre_idx + 1] = max(1 + fun(idx + 1, idx, arr, n, dp), fun(idx + 1, pre_idx, arr, n, dp));
    }
    else
    {
        return dp[idx][pre_idx + 1] = fun(idx + 1, pre_idx, arr, n, dp);
    }
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return fun(0, -1, arr, n, dp);
}
