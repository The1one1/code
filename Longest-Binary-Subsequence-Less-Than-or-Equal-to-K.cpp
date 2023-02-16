#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        vector<int> prefix_Zero_cnt(s.size() + 1, 0);
        for (int i = 1; i <= s.size(); i++)
        {
            if (s[i - 1] == '0')
                prefix_Zero_cnt[i] = prefix_Zero_cnt[i - 1] + 1;
            else
                prefix_Zero_cnt[i] = prefix_Zero_cnt[i - 1];
        }

        int i = 0, j = 0, ans = 0;
        while (i <= j and j < s.size())
        {
            string sub = s.substr(i, j - i + 1);
            bitset<1001> b{sub};
            // convert binary into int
            int num = b.to_ulong();
            if (num <= k)
            {
                int x1 = prefix_Zero_cnt[i];
                ans = max(ans, j - i + 1 + x1);
                j++;
            }
            else if (num > k)
            {
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    string str = "00101001";
    Solution s;
    int k = 1;
    // cout << s.longestSubsequence(str, k) << endl;
    char c = 'h';
    cout << string(5, c) << endl;
}