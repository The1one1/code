#include <bits/stdc++.h>
using namespace std;
vector<int> c, p, t;
vector<vector<int>> dp;

int knapSack(int n, int w)
{
    if (n < 0 or w <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (t[n] <= w)
        return dp[n][w] = max((knapSack(n - 1, w - t[n]) + c[n] * p[n]), knapSack(n - 1, w));
    else
        return dp[n][w] = knapSack(n - 1, w);
}

int main() {
    int t1; cin >> t1;
    while (t1--) {
        int n, w; cin >> n >> w;
        dp = vector<vector<int>>(n + 1, vector<int>(w + 1, -1));
        c = p = t = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
            cin >> c[i];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        for (int i = 0; i < n; i++)
            cin >> t[i];

        cout << knapSack(n - 1, w) << endl;
    }
}
