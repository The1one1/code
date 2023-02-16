
int matrixMultiplication(vector<int> &a, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            int mini = 1e9, step = 0;
            if (i == j)
                continue;
            for (int k = i; k < j; k++)
            {
                step = a[i - 1] * a[k] * a[j] + dp[i][k] + dp[k + 1][j];
                if (step < mini)
                    mini = step;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}