#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int knapSack(int s[], int n, int amt, vector<long long int> &dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = amt; j >= 1; j--)
            {
                if (s[i - 1] <= j)
                    dp[j] = dp[j] + dp[j - s[i - 1]];
            }
            for (int i = 0; i <= n; i++)
            {
                cout << dp[i] << " ";
            }
            cout << endl;
        }
        return dp[amt];
    }

    long long int count(int S[], int n, int W)
    {
        // vector<vector<long long int>> dp(2, vector<long long int>(W + 1, 0));
        vector<long long int> dp(W + 1, 0);
        dp[0] = 1;
        return knapSack(S, n, W, dp);
    }
};

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution ob;
    cout << ob.count(arr, n, m) << endl;
}