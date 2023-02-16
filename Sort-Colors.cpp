#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &a)
    {
        int i = 0, j = 0, k = a.size() - 1;
        while (j <= k)
        {
            switch (a[j])
            {
            case 0:
                swap(a[i], a[j]);
                i++;
                j++;
                break;

            case 1:
                j++;
                break;

            case 2:
                swap(a[j], a[k]);
                k--;
                break;
            }
        }
    }
};

int main()
{
    vector<int> v = {1, 2, 1, 0, 2, 0, 2, 0, 1, 1};
    Solution s;
    s.sortColors(v);
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}