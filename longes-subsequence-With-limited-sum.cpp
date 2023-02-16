class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end(), [&](auto x, auto y) { return x < y;})
        // prefix sum
        for(int i = 1; i < n; i++) {
            nums[i] = nums[i - 1] + nums[i];
        }
        vector<int> answer;
        for(auto &it: queries) {
            int x = lower_bound(nums.begin(), nums.end(), it) - nums.begin();
            if(x < nums.size() && nums[x] == it) {
                answer.push_back(x);
            } else {
                answer.push_back(x - 1);
            }
        }
        return answer;
    }
};