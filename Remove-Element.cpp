class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int  i = 0, j = a.size() - 1, cnt = 0;
        while(i <= j){
            bool flag = true;
            if(a[i] == val and a[j] != val){
                swap(a[i], a[j]);
                flag = false;
                i++, j--;
            }
            if(a[i] != val and a[j] == val){
                flag = false;
                j--;
                cnt++;
            }
            if(a[i] == val and a[j] == val){
                cnt++;
                j--;
            }

            if(flag){
                i++;
            }
        }
        return a.size() - cnt;
    }
};