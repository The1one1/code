#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int fun(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if (i == 0 and j == 0)
            return mat[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];
        int cnt1 = 0, cnt2 = 0;
        if (j - 1 >= 0 and mat[i][j - 1] != 1)
            cnt1 = fun(i, j - 1, mat, dp);

        if (i - 1 >= 0 and mat[i - 1][j] != 1)
            cnt2 = fun(i - 1, j, mat, dp);

        return dp[i][j] = mat[i][j] + max(cnt1, cnt2);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> > dp(n, vector<int> (m, -1));
        return fun(n-1, m-1, grid, dp);
    }
};




















// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int minPathSum(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         int m = grid[0].size();

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (i == 0 and j == 0)
//                 {
//                     continue;
//                 }
//                 else if (i == 0 or j == 0)
//                 {
//                     if (i == 0)
//                     {
//                         grid[i][j] += grid[i][j - 1];
//                     }
//                     else if (j == 0)
//                     {
//                         grid[i][j] += grid[i - 1][j];
//                     }
//                 }
//                 else
//                 {
//                     grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
//                 }
//             }
//         }
//         return grid[n - 1][m - 1];
//     }
// };