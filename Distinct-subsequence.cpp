#include <bits/stdc++.h>
using namespace std;
#define int long long

#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Solution
{
public:
    int distLcs(string &s, string &t, vector<int> &dp)
    {
        dp[0] = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = t.size(); j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[t.size()];
    }

    int numDistinct(string &s, string &t)
    {
        vector<int> dp(t.size() + 1, 0);
        return distLcs(s, t, dp);
    }
};

signed main()
{
#ifndef ONLINE_JUDGE
    inout
#endif
        string s1,
        s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.numDistinct(s1, s2) << endl;
}