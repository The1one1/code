#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool check(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget, int len) {
        int ans = 0, mx = -1;
        set<int> s;
        for(int i = 1; i <= len; i++) {
            ans += runningCosts[i-1];
            s.insert(chargeTimes[i-1]);
            // mx = max(mx, chargeTimes[i-1]);
        }
        cout <<"h1= ";
        for(auto &it: s) {
            cout << it <<" ";
        } cout << endl;
        
        int i = 1, j = len + 1;
        auto it = s.begin();
        if(!s.empty()) {
            it = s.end();
            it--;
        }

        int y = (!s.empty() ? *it : 0) + len * ans;
        
        cout <<"y="<<y<<"  *(s.end()--)="<<*it<<endl;
        while( i < j and j <= chargeTimes.size() and (j - i + 1) <= len) {
            if(y <= budget) return true;
            ans += (runningCosts[j-1] - runningCosts[i-1]);
            if(!s.empty())
                s.erase(chargeTimes[i-1]);
                
            s.insert(chargeTimes[j-1]);
            
            auto it = s.end();
            it--;
            y = *it + len * ans;
            i++;
            j++;
            cout <<"h2= ";
            for(auto &it: s) {
            cout << it <<" ";
        } cout << endl;
        }
        if(y <= budget) return true;
        else return false;
    }
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int low = 0, high = chargeTimes.size();
        while( high - low > 1) {
            int mid = (low + high)/2;
            cout << low <<" "<<mid<<" "<<high<< endl;
            if(check(chargeTimes, runningCosts, budget, mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << low <<" " << high << endl;
        if(check(chargeTimes, runningCosts, budget , high)) return high;
        else if(check(chargeTimes, runningCosts, budget , low)) return low;
        else return 0;
    }
};


int main() {
    Solution s;
    
    vector<int> chargeTimes = {11,12,19};
    vector<int> runningCosts = {10, 8, 7};
    long long budget = 19;
    cout << s.maximumRobots(chargeTimes, runningCosts, budget) << endl;
    return 0;
}