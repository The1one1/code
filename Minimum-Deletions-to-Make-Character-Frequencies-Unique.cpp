#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        unordered_map<char, int> m;
        array<int, 26> freq{};
        for (auto &it : s)
            m[it]++;

        map<int, int> p;
        for (auto &it : m)
            p[it.second]++;

        int cnt = 0;
        for (auto it = p.rbegin(); it != p.rend(); it++)
        {
            int key = it->first;
            if (key <= 0)
                break;
            int value = it->second;
            if (value == 1)
                continue;
            cnt += (value - 1);
            p[key - 1] += (value - 1);
        }
        return cnt;
    }
};

int main()
{
    string s = "accdcdadddbaadbc";
    Solution obj;
    cout << obj.minDeletions(s) << endl;
}