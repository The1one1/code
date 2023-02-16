#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fun(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];
        int cnt = 0;
        if (j - 1 >= 0 and mat[i][j - 1] != 1)
            cnt += fun(i, j - 1, mat, dp);

        if (i - 1 >= 0 and mat[i - 1][j] != 1)
            cnt += fun(i - 1, j, mat, dp);

        return dp[i][j] = cnt;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] or obstacleGrid[n - 1][m - 1])
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return fun(n - 1, m - 1, obstacleGrid, dp);
    }
};