#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& a, int k, int len) {
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum += a[i];
            if(sum >= k) return 1;
        }
        
        int i = 0, j = len;
        while(j < a.size()) {
            if(sum >= k) return 1;
            sum -= (a[i] - a[j]);
            i++, j++;
        }
        return sum >= k;
    }
    
    int shortestSubarray(vector<int>& a, int k) {
        if(accumulate(a.begin(), a.end(), 0) < k) return -1;
        int low = 1, high = a.size();
        
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(check(a, k, mid)) {
                high  = mid;
            }
            else low = mid + 1;
            cout << "low="<<low<<" mid="<<mid<<endl;
        }
        
        if(check(a, k, low)) return low;
        else return high;
    }
};

int main() {
    Solution s;
    vector<int> a = {2, -1, 2};
    cout << s.shortestSubarray(a, 3) << endl;
}