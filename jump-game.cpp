#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

class Solution
{
public:
    bool can(vector<int> &nums, int idx, vector<bool> &dp)
    {
        int reach = 0;

        for(int i = 0; i < nums.size() and reach < nums.size(); i++){
            reach = max(reach, i + nums[i]);
        }
        return reach >= nums.size()-1;
    }

    bool canJump(vector<int> &nums, int idx = 0)
    {
        vector<bool> dp(nums.size(), false);
        return can(nums, 0, dp);
    }
};

signed main()
{
#ifndef ONLINE_JUDGE
    inout
#endif
        int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    Solution sol;
    cout << sol.canJump(v, 0) << endl;
}