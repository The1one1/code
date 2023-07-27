#include <iostream>
#include <vector>
using namespace std;
#define int unsigned long long

int binarySearch(const int& a, const int& b, const int& c, const int& q) {
    int l = 0, r = 1e11;

    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if ((a * mid * mid) + (b * mid) <= (q - c)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);

        int a = 4 * n, b = 0, c = 0;
        for (auto& it : arr) {
            cin >> it;
            b += it;
            c += (it * it);
        }
        b *= 4;

        cout << binarySearch(a, b, c, q) << endl;
    }
    return 0;
}
