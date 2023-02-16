#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t = 1;
    while (t--) {
        int n = 5; 
        vector<int> arr = {1, 2, 3, 4, 5};
        // for(int i = 0; i < n; i++) cin >> arr[i];
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if(sum == n) {
            cout << 0 << endl;
            continue;
        }

        if(sum < n) {
            cout << 1 << endl;
            continue;
        }

        cout << sum - n << endl;
    }
    
}