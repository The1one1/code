#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        int r = p % k, ans = 0;
        int x = n - 1 - (n - 1) % k;

        /*
          1 2 3 4 5 6 7 8 9 10 11 12 13 14
                               -----------
                                n % k >= r
        */
        if ((n - 1) % k >= r) {
            ans = r + (x / k) * r;
        }

        /*

            1 2 3 4 5 6 7 8 9 10 11 12
                            ----------
                            n % k < r
        */
        else {

            ans = r + (x / k) * (n % k) + (max(x - k, 0ll) / k) * (max(r - n % k, 0ll));
        }
        ans += ((p - r) / k + 1);
        cout << ans << endl;
    }
}


vector<int> arr(n);
for(int i = 0; i < n; i++) {
    cin >> arr[i];
}

// check first increasnig then decreasing
bool isIncreasing = true;
for(int i = 1; i < n; i++) {
    if(arr[i] < arr[i - 1]) {
        isIncreasing = false;
        break;
    }
}

