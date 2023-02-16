class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> v;
        int i = 1, j = arr.size() - 1;
        while (i <= j)
        {
            if (arr[j] != i)
            {
                int k = j - 1;
                while(arr[k] != i){
                    k--;
                }
                int x = arr[j];
                v.push_back(k+1);
                v.push_back(j+1);

                for(int l = j - 1; l > 0; l--){
                    arr[l] = arr[l-1];
                }
                arr[0] = x;
            }
            i++, j--;
        }

        for(int i = 0; i < arr.size(); i++){
            cout << arr[i]<<" ";
        }cout << endl;
        return v;
    }
};