#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];

        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            ans+= arr[i]/k;
            arr[i] = arr[i]%k;
        }

        sort(arr, arr+n);
        int i = 0, j = n-1;
        while(i < j){
            if(arr[i] + arr[j] < k){
                i++;
            }
            else{
                i++, j--;
                ans++;
            }
        }
        cout << ans << endl;
    }
}