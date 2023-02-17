#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n, s; cin >> n >> s;
        vector<int> v(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        if(sum <= s) {
            cout << 0 << endl;
        }
        else {
            int ind = 0, sum = 0, m = 0;
            for(int i = 0; i <  n; i++) {
                sum += v[i];
                if(sum >= s) {
                    sum -= v[ind];
                }
                if()
            }
        }

    }
}












// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// bool check(vector<int> &preSum, int mid, int i, int rmv, int s) {
//     if(mid >= i) {
//         return preSum[mid] <= rmv;
//     }
//     return preSum[mid] <= s;    
// }

// int bs(vector<int> &preSum, int s, int i, int n, int rmv) {
//     int l = 0, r = n - 1;
//     while(r - l > 1) {
//         int mid = (l + r) / 2;
//         if(check(preSum, mid, i, rmv, s)) {
//             l = mid;
//         }
//         else r = mid;
//     }
//     if(check(preSum, r, i, rmv, s)) return r;
//     return l;
// }

// signed main(){
//     int t; cin >> t;
//     while(t--) {
//         int n, s; cin >> n >> s;
//         vector<int> a(n);
//         for(int i = 0; i < n; i++) cin >> a[i];

//         vector<int> preSum = a;
//         for(int i = 1; i < n; i++) {
//             preSum[i] += preSum[i - 1];
//         }

//         int cnt = upper_bound(preSum.begin(), preSum.end(), s) - preSum.begin();
//         int ind = 0;

//         for(int i = 0; i < n; i++) {
//             int j = bs(preSum, s, i, n, s + a[i]);
//             if(cnt < j + 1) {
//                 cnt = max(cnt, j + 1);
//                 ind = i + 1;
//             }
//         }
//         cout << ind << endl;
//     }
// }