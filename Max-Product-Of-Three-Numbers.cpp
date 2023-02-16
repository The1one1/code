#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> maxEle(4, INT_MIN), minEle(3, INT_MAX);

    for(int i = 0; i < n; i++) {
        if(arr[i] <= minEle[1]) {
            if(arr[i] != minEle[1]) {
                minEle[2] = minEle[1];
                minEle[1] = arr[i];
            }
        }
        else if( arr[i] <= minEle[2]){
            minEle[2] = arr[i];
        }

        if(arr[i] >= maxEle[1]) {
            if(arr[i] != maxEle[1]) {
                maxEle[3] = maxEle[2];
                maxEle[2] = maxEle[1];
                maxEle[1] = arr[i];
            }
        }
        else if(arr[i] >= maxEle[2]){
            if(arr[i] != maxEle[2]){
                maxEle[3] = maxEle[2];
                maxEle[2] = arr[i];
            }
        }
        else if(arr[i] >= maxEle[3]){
            maxEle[3] = arr[i];
        }
    }
    int x = minEle[1] * minEle[2] * maxEle[1];
    x = max(x, maxEle[1] * maxEle[2] * maxEle[3]);
    cout << x << endl;
}