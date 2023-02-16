class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        
        vector<vector<int> > v;
        sort(a.begin(), a.end());
        int n = a.size();
        for(int k = 0; k < n; k++)
        {
            if(k > 0 and a[k] == a[k-1]) continue;
            int target = -1 * a[k];
            int i = k + 1, j = a.size()-1;
            while(i < j)
            {
                if(a[i] + a[j] < target) {
                    i++;
                    while(i < j and a[i-1] == a[i])
                        i++;
                }
                else if(a[i] + a[j] > target) {
                    j--;
                    while(i < j and a[j+1] == a[j])
                        j--;
                }
                else if(a[i] + a[j] == target) {
                    v.push_back(vector<int>{a[k], a[i], a[j]});
                }
                i++;
                while(i < j and a[i-1] == a[i]) i++;
            }
        }
        return v;
    }
};