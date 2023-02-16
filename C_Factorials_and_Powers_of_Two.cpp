#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

signed main()
{
    vector<int> factorial;
    for (int fac = 1, i = 1; i <= 15; i++) {
        fac = fac * i;
        factorial.push_back(fac);
    }

    vector<pair<int, int>> SumCntPair;

    for (int i = 0; i <= (int)pow(2, factorial.size()); i++) {
        int sum = 0, cnt = 0, j = 0;
        while (j < 16) {
            if (i & (1 << j)) {
                cnt++;
                sum += factorial[j];
            }
            j++;
        }
        SumCntPair.push_back({sum, cnt});
    }

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // cout <<"n="<<n<<endl;
        int cnt = __builtin_popcountll(n);
        // cout <<"cnt="<<cnt<<endl;
        for(auto &[sum, EleCnt]:SumCntPair) {
            if(n - sum >= 0) {
                cnt = min(cnt, EleCnt + __builtin_popcountll(n - sum));
            }
        }
        cout << cnt << endl;
    }
}