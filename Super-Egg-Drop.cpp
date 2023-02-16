#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fun(int eggCnt, int floor, vector<vector<int>> &dp)
    {
        if (eggCnt == 1 or floor == 1 or floor == 0)
            return floor;
        if (dp[eggCnt][floor] != -1)
            return dp[eggCnt][floor];

        int minEle = INT_MAX;
        int low = 1, high = floor;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int down = fun(eggCnt - 1, mid - 1, dp); // if egg break
            int up = fun(eggCnt, floor - mid, dp);  // if not break
            minEle = min(minEle, 1 + max(down, up));

            if (down <= up)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return dp[eggCnt][floor] = minEle;
    }
    int superEggDrop(int k, int n)
    {
        //! recursive + memoization
        // vector<vector<int>> dp(k+1, vector<int>(n + 1, -1));
        // return fun(k, n, dp);

        //! iterative code
        vector<vector<int>> dp(k+1, vector<int>(n + 1, 0));

        for(int eggCnt = 1; eggCnt <= k; eggCnt++) 
        {
            for(int floor = 1; floor <= n; floor++)
            {
                if(eggCnt == 1 or floor == 1 or floor == 0)
                    dp[eggCnt][floor] = floor;
                else
                {
                    int minEle = INT_MAX;
                    int low = 1, high = floor;

                    while(low <= high)
                    {
                        int mid = (low + high) / 2;
                        int down = dp[eggCnt - 1][mid - 1]; // if egg break
                        int up = dp[eggCnt][floor - mid];
                        minEle = min(minEle, 1 + max(down, up));

                        if(down <= up)
                            low = mid + 1;
                        else
                            high = mid - 1;
                    }
                    dp[eggCnt][floor] = minEle;
                }
            }
        }
        for(int i = 1; i < k+1; i++){
            for(int j = 1; j < n+1; j++){
                cout << dp[i][j] << " ";
            }cout << endl;
        }cout << endl;
        return dp[k][n];
    }
};

int main()
{
    Solution s;
    cout << s.superEggDrop(6, 14) << endl;
    return 0;
}