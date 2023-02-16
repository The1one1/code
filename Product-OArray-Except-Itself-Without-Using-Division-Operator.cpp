#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &it: a)
        cin >> it;

    vector<int> pre_arr(n), suff_arr(n);

    pre_arr[0] = a[0];
    for(int i = 1; i < n; i++)
        pre_arr[i] = a[i] * pre_arr[i-1];

    suff_arr[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        suff_arr[i] = suff_arr[i+1] * a[i];

    vector<int> ans(n);

    ans[0] = suff_arr[1];
    ans[n-1] = pre_arr[n-2];

    for(int i = 1; i <= n-2; i++)
        ans[i] = pre_arr[i-1] * suff_arr[i+1];
    
    for_each(ans.begin(), ans.end(), [&](auto it){ cout << it << " ";});cout << endl;
}