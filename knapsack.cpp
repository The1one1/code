#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

int knapSack1(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(wt[i-1] <= j){
                dp[i%2][j] = max(val[i-1] + dp[(i-1)%2][j- wt[i-1]], dp[(i-1)%2][j]);
            }
            else dp[i%2][j] = dp[(i-1)%2][j];
        }
    }

    return dp[n%2][W];
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(2, vector<int>(W + 2, 0));
    return knapSack1(W, wt, val, n, dp);
}

signed main()
{
#ifndef ONLINE_JUDGE
    inout
#endif
        int n,
        w;
    cin >> n >> w;
    int val[n], wt[n];

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << knapSack(w, wt, val, n);
}