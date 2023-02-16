class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxCnt = n * m;
        int xMinCnt = n, yMinCnt = m;
        for(auto &it: ops)
        {
            
            int x = it[0], y = it[1];
            cout <<"x="<<x<<" y="<<y<<endl;
            if(x == 0 and y == 0) continue;
            xMinCnt = min(xMinCnt, x);
            yMinCnt = min(yMinCnt, y);
        }
        return min(maxCnt, xMinCnt * yMinCnt);
    }
};