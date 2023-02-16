#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> preMax(n), suffMin(n);
    preMax[0] = arr[0];
    suffMin[n-1] = arr[n-1];
    for(int i = 1; i < n; i++)
        preMax[i] = max(preMax[i-1], arr[i]);

    for(int i = n-2; i >= 0; i--)
        suffMin[i] = min(suffMin[i+1], arr[i]);

    for(int i = 0; i < n-1; i++){
        if(preMax[i] <= suffMin[i+1]){
            cout << i + 1 <<"\n";
            break;
        }
    }
}