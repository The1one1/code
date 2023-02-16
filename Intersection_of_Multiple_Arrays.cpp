#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<vector<int>>& nums) {
		vector<int> a(1001);

		for (int i = 0; i < nums.size(); i++) {
			for (auto &ele : nums[i]) {
				a[ele]++;
			}
		}

		vector<int> arr;
		for(int i = 0; i < a.size(); i++) {
			if(a[i] == nums.size()) {
				arr.push_back(i);
			}
		}
		sort(arr.begin(), arr.end());
		return arr;
	}
};