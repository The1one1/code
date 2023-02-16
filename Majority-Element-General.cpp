#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n);
    vector<int> a;
    int val = arr[0], cnt = 1;
    for(int i = 1; i < n; i++) {
        if(val == arr[i]){
            cnt++;
        }
        else if(arr[i] != val) {
            if(cnt > n/k) a.push_back(arr[i-1]);
            cnt = 1;
            val = arr[i];
        }
    }
    if(cnt > n/k) a.push_back(arr[n-1]);
    
    cout <<"[";
    for_each(a.begin(), a.end()-1, [](int it){cout << it <<", ";});
    cout << a.back() <<"]";
}