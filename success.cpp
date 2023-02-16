class Solution
{
public:
    int fun(int l, int r, vector<pair<int, int>> &pre, string &s)   // to calculate the no of candle's btw the given range
    {
        return pre[r].first - pre[l].first + (s[l] == '|' ? 1 : 0);
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
    {
        vector<pair<int, int>> pre(s.size(), {0, 0});
        vector<int> ans, p;

        int x = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '|')   //to store the index of candles
                p.push_back(i);

            if (s[i] == '*')
            {
                x++; 
                if (i != 0)
                    pre[i] = pre[i - 1];
            }
            else if (s[i] == '|' and i == 0)
                pre[i] = {1, 0};
            
            else if (s[i] == '|')
            {
                if (pre[i - 1].first >= 1)
                    pre[i].second = pre[i - 1].second + x;

                else
                    pre[i].second = 0;

                pre[i].first = pre[i - 1].first + 1;
                x = 0;
            }
        }

        for (auto &v : queries)
        {
            int l = v[0], r = v[1];
            if (fun(l, r, pre, s) >= 2)  
            {
                l = *lower_bound(p.begin(), p.end(), l);   // to find the position of candle
                ans.push_back(pre[r].second - pre[l].second);
            }
            else
                ans.push_back(0);
        }
        return ans;
    }
};