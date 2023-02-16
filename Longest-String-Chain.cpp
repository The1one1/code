class Solution
{
public:
    bool comp(string s1, string s2)
    {
        int i = s1.size() - 1, j = s2.size() - 1;
        while (i >= 0 and j >= 0)
        {
            if (s1[i] == s2[j])
                i--, j--;
            else
                i--;
        }
        if ((i < 0 or i == 0) and j < 0)
            return 1;
        return 0;
    }

    int fun(vector<string> &arr, int idx, int preidx, vector<vector<int>> &dp)
    {
        for(int idx = arr.size()-1; idx >= 0; idx--)
        {
            for(int preidx = idx-1; preidx >= -1; preidx--)
            {
                if (preidx == -1)
                    dp[idx][preidx + 1] = max(1 + dp[idx + 1][idx+1], dp[idx + 1][preidx+1]);
                
                else if (arr[idx].size() == arr[preidx].size() + 1 and comp(arr[idx], arr[preidx]))
                    dp[idx][preidx + 1] = max(1 +dp[idx + 1][idx+1], dp[idx + 1][preidx+1]);
        
                else
                dp[idx][preidx + 1] = dp[idx + 1][preidx+1];
            }
        }
        return dp[0][0];
    }

    int longestStrChain(vector<string> &arr)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size() + 1, -1));
        sort(arr.begin(), arr.end(), [](string s1, string s2)
             { return s1.size() < s2.size(); });
        return fun(arr, 0, -1, dp);
    }
};








class Solution
{
public:
    bool comp(string s1, string s2)
    {
        int i = s1.size() - 1, j = s2.size() - 1;
        while (i >= 0 and j >= 0)
        {
            if (s1[i] == s2[j])
                i--, j--;
            else
                i--;
        }
        if ((i < 0 or i == 0) and j < 0)
            return 1;
        return 0;
    }

    int fun(vector<string> &arr, int idx, int preidx, vector<vector<int>> &dp)
    {
        if (idx >= arr.size())
            return 0;
        if (dp[idx][preidx + 1] != -1)
            return dp[idx][preidx + 1];
        if (preidx == -1)
            return dp[idx][preidx + 1] = max(1 + fun(arr, idx + 1, idx, dp), fun(arr, idx + 1, preidx, dp));
        
        else if (arr[idx].size() == arr[preidx].size() + 1 and comp(arr[idx], arr[preidx]))
            return dp[idx][preidx + 1] = max(1 + fun(arr, idx + 1, idx, dp), fun(arr, idx + 1, preidx, dp));
        
        else
            return dp[idx][preidx + 1] = fun(arr, idx + 1, preidx, dp);
    }

    int longestStrChain(vector<string> &arr)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size() + 1, -1));
        sort(arr.begin(), arr.end(), [](string s1, string s2)
             { return s1.size() < s2.size(); });
        return fun(arr, 0, -1, dp);
    }
};