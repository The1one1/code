class Solution
{
public:
    int fun(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {

        if (i < 0 or j >= m or i >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        ans = max(ans, arr[i][j] + fun(i - 1, j + 1, n, m, arr, dp));
        ans = max(ans, arr[i][j] + fun(i, j + 1, n, m, arr, dp));
        ans = max(ans, arr[i][j] + fun(i + 1, j + 1, n, m, arr, dp));
        return dp[i][j] = ans;
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, fun(i, 0, n, m, M, dp));
        }
        return ans;
    }
};

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> arr)
    {

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                int ans = 0;
                if (i - 1 >= 0)
                    ans = max(ans, arr[i][j] + dp[i - 1][j + 1]);

                ans = max(ans, arr[i][j] + dp[i][j + 1]);
                ans = max(ans, arr[i][j] + dp[i + 1][j + 1]);
                dp[i][j] = ans;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            cnt = max(cnt, dp[i][0]);
        }
        return cnt;
    }
};