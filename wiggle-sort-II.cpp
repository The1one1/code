#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int n = a.size();
        int j = n-1, i = (n-1)/2, k = 0;
        while(i >= 0){
            nums[k++] = a[i--];
            if(j >= 0 and k < n)
                nums[k++] = a[j--];
        }
    }
};

int main(){
    vector<int> v = {6,1 ,5 ,1 ,1 ,6 ,4};
    Solution s;
    s.wiggleSort(v);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
