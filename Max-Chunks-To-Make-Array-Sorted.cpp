#include<bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &ele : arr) {
        cin >> ele;
    }
    int minEle = arr.front(), x = arr[0], idx = 0, cnt = 0;
    if(n == 1 or arr[0] <= arr[1]){
        cnt++;
    }
    for(int i = 1; i < n; i++) {
        if(arr[i] < x) {
            minEle = min(minEle, arr[i]);
            if(i == n-1) cnt++;
            continue;
        }
        else if((i - idx) == (x - minEle + 1)) {
            cnt++;
            minEle = x;
            idx = i - 1;
        }
        x = max(x, arr[i]);
    }
    cout << cnt << endl;
}