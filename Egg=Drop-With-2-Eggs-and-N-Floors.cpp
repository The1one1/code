#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fun(int eggCnt, int floor, vector<vector<int>> &dp)
    {
        if (eggCnt == 1 or floor == 1 or floor == 0) // if there is only one egg or if there is only one floor, then there is only one way to drop the egg
            return floor;
        if (dp[eggCnt][floor] != -1)
            return dp[eggCnt][floor];

        int minEle = INT_MAX; // minimum number of ways to drop the egg
        for (int i = 1; i <= floor; i++)
        {
            /*
                ----------
                    |  => floor
                    |
                    |
                    |  => ith floor , now we check for all floor, (from which floor should I start to check so that I can get min no of way to find critical floor)
                    |
                    |
                    |  => 1st floor
                ----------
            */
            minEle = min(minEle, 1 + max(fun(eggCnt - 1, i - 1, dp), fun(eggCnt, floor - i, dp)));
        }
        return dp[eggCnt][floor] = minEle;
    }
    int twoEggDrop(int n)
    {
        //! recursive + memoization

        // vector<vector<int>> dp(3, vector<int>(n + 1, -1));
        // return fun(2, n, dp);

        //! iterative code
        vector<vector<int>> dp(6, vector<int>(n + 1, 0));

        for (int eggCnt = 1; eggCnt <= 5; eggCnt++)
        {
            for (int floor = 1; floor <= n; floor++)
            {
                if (eggCnt == 1 or floor == 1 or floor == 0)
                    dp[eggCnt][floor] = floor;

                else
                {
                    int minEle = INT_MAX;
                    for (int i = 1; i <= floor; i++)
                        minEle = min(minEle, 1 + max(dp[eggCnt - 1][i - 1], dp[eggCnt][floor - i]));

                    dp[eggCnt][floor] = minEle;
                }
            }
        }
        for(int i = 1; i < 6; i++){
            for(int j = 1; j < n+1; j++){
                cout << dp[i][j] << " ";
            }cout << endl;
        }cout << endl;
        return dp[2][n];
    }
};

int main()
{
    Solution s;
    cout << s.twoEggDrop(14) << endl;
    return 0;
}