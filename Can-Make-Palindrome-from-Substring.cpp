#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        // ! arrangement of char is allowed btw given range
        vector<bool> v;
        vector<vector<int>> dp(26, vector<int>(s.size(), 0));   // to store the count of characters in the string so that we can 
                                                                // count the occurence of each character in given range

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (j == 0)
                {
                    if ((char('a' + i) == s[j]))
                        dp[i][j] = 1;
                }

                else if (char('a' + i) == s[j])
                    dp[i][j] = dp[i][j - 1] + 1;

                else
                    dp[i][j] = dp[i][j - 1];
            }
        }

        for (auto &it : queries)
        {
            int l = it[0], r = it[1], k = it[2];

            int oddCnt = 0;    //* to count the number of odd occurence of characters in given range

            for (int i = 0; i < 26; i++)
            {
                int cnt = dp[i][r] - dp[i][l] + (s[l] == char('a' + i) ? 1 : 0);
                if (cnt % 2 == 1)
                    oddCnt++;
            }

            if ((r - l + 1) % 2 == 1)    //* if length of the string is odd then one odd character is allowed in palindrome
                oddCnt--;

            if (oddCnt / 2 <= k)   // * if k is greater than or equal to half of the odd character count then it is palindrome
                v.push_back(1);
            else
                v.push_back(0);
        }
        return v;
    }
};

int main()
{
    string str = "pazcds";

    vector<vector<int>> v = {{1, 5, 5}, {4, 5, 1}, {5, 5, 1}, {2, 5, 2}, {3, 4, 1}, {0, 3, 0}, {1, 2, 0}, {2, 5, 0}, {5, 5, 1}, {0, 3, 1}, {1, 5, 1}, {2, 5, 0}, {5, 5, 1}, {0, 1, 0}, {5, 5, 1}, {4, 5, 1}, {1, 3, 3}};
    Solution s;
    vector<bool> v1 = s.canMakePaliQueries(str, v);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}
