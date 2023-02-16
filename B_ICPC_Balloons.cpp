#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        vector<bool> arr(27);
        int cnt = 0;
        for(auto &it: str) {
            int ind = (it - 'A');
            if(!arr[ind]) {
                cnt += 2;
                arr[ind] = 1;
            }
            else cnt++;
        }
        cout << cnt << endl;
    }
}