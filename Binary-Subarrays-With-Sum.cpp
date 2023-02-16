#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> A, int S)
    {
        if (S == 0)
            return helper(A); // deal with S == 0
        int prev = -1;
        int lo = 0, hi = 0;
        int sum = 0;
        int cnt = 0;
        // deal with S > 0 but cases like[0,0,0,0,0]
        while (lo < A.size() && A[lo] == 0)
        {
            lo++;
            hi++;
        }
        while (hi < A.size())
        {
            if (sum + A[hi] == S)
            {
                sum += A[hi];
                cnt += 1 + (lo - prev - 1);
                hi++;
            }
            else if (sum + A[hi] < S)
            {
                sum += A[hi];
                hi++;
            }
            else
            {
                sum -= A[lo];
                prev = lo;
                lo++;
                while (A[lo] == 0)
                    lo++;
            }
        }
        return cnt;
    }
    int helper(vector<int> A)
    {
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == 0)
            {
                cnt++;
                res += cnt;
            }
            else
            {
                cnt = 0;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v = {0, 1, 1, 1, 1};
    Solution s;
    cout << s.numSubarraysWithSum(v, 3) << endl;
    return 0;
}