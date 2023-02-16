#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void floodFill2(vector<vector<int>> &image, int sr, int sc, int color, int defaultColor)
    {
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 or sc < 0) return;
        if(sr >= n or sc >= m) return;
        if (image[sr][sc] != defaultColor) return;

        image[sr][sc] = color;
        floodFill2(image, sr + 1, sc, color, defaultColor);
        floodFill2(image, sr - 1, sc, color, defaultColor);
        floodFill2(image, sr, sc + 1, color, defaultColor);
        floodFill2(image, sr, sc - 1, color, defaultColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int defaultColor = image[sr][sc];
        if(defaultColor == color) return image;
        floodFill2(image, sr, sc, color, defaultColor);
        return image;
    }
};

signed main()
{
    vector<vector<int>> v = {{0, 0, 0}, {0, 0, 0}};
    Solution s;

    for (auto i : s.floodFill(v, 0, 0, 0))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}