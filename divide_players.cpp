#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long dividePlayers(vector<int>& skill) {
		int n = skill.size();
		sort(skill.begin(), skill.end());
		int ans = 0;
		for (int i = 0; i < n / 2; i++) {
			if(skill[i] + skill[n - i - 1] != skill[0] + skill.back()) return -1;
			ans += (skill[i] * skill[n - 1 - i]);
		}
		return ans;
	}
};