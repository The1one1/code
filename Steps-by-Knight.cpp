#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<pair<int, int>> v = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    void fun(vector<int> &TargetPos, int N, int row, int col, int &ans, int cnt, vector<vector<int>> &visited)
    {
        if (row == TargetPos[0] and col == TargetPos[1])
        {
            ans = max(ans, cnt);
            return;
        }

        if (row < 0 or row >= N or col < 0 or col >= N or visited[row][col] == 1)
        {
            return;
        }

        visited[row][col] = 1;
        for (int i = 0; i < 8; i++)
        {
            int r = row + v[i].first, c = col + v[i].second;
            fun(TargetPos, N, r, c, ans, cnt + 1, visited);
        }
        visited[row][col] = 0;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        vector<vector<int>> visited(N + 1, vector<int>(N + 1, 0));
        int ans = 0;
        fun(TargetPos, N, KnightPos[0], KnightPos[1], ans, 0, visited);
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
}