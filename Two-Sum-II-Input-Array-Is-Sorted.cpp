class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        a.resize(a.size(), distance(a.begin(), unique(a.begin(), a.end())));
        for(int i = 0; i < a.size(); i++){
            int low = i + 1, high = a.size() - 1;
            while(low <= high){
                int mid = (high - low)/2 + low;
                if(a[i] + a[mid] < target){
                    low = mid + 1;
                }
                else if(a[i] + a[mid] > target){
                    high = mid - 1;
                }
                else if(a[i] + a[mid] == target){
                    return vector<int>{i+1, mid+1};
                }
                else low = mid + 1;
            }
        }
        return vector<int> {i+1, j+1};
    }
};
