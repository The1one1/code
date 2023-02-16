class Solution
{
public:
    void fun(vector<vector<int>> &m, int n, int row, int col, vector<string> &ans, string curr)
    {
        if (row >= n or col >= n or row < 0 or col < 0 or m[row][col] == 0)
            return;

        if (row == n - 1 and col == n - 1) {
            ans.push_back(curr);
            return;
        }
        m[row][col] = 0;
        fun(m, n, row + 1, col, ans, curr + 'D');
        fun(m, n, row - 1, col, ans, curr + 'U');
        fun(m, n, row, col + 1, ans, curr + 'R');
        fun(m, n, row, col - 1, ans, curr + 'L');

        m[row][col] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        return fun(m, n, 0, 0, ans, str);
    }
};