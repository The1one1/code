#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countLatticePoints(vector<vector<int>>& circles) {
		int ans = 0;

		for (int i = 0; i <= 200; i++) {
			for (int j = 0; j <= 200; j++) {
				for (int k = 0; k < circles.size(); k++) {
					if (pow((circles[k][0] - i), 2) + pow((circles[k][1] - j), 2) <= pow(circles[k][2], 2)) {
						ans++;
						break;
					}
				}
			}
		}
		return ans;
	}
};