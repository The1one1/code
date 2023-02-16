#include <bits/stdc++.h>
using namespace std;

int fun(int idx, int n, vector<vector<int>> &points, vector<vector<int> > &dp)
{
    if (n <= 0)
        return 0;
    if(dp[n][idx] != 0) return dp[n][idx];

    int cost = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != idx)
        {
            cost = max(cost, points[n - 1][i] + fun(i, n - 1, points, dp));
        }
    }
    return dp[n][idx] = cost;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int> > dp(n, vector<int> (3, 0));
    int x1 = points[n - 1][0] + fun(0, n - 1, points, dp);
    x1 = max(x1, points[n - 1][1] + fun(1, n - 1, points, dp));
    x1 = max(x1, points[n - 1][2] + fun(2, n - 1, points, dp));
    return x1;
}


