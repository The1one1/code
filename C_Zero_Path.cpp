#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<bitset<2001>>> dp(n + 1, vector<bitset<2001>>(m + 1, bitset<2001> (0)));
        int a[n+1][m+1];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                if(a[i][j] == -1) a[i][j] = 0;
            }
        }

        if((n + m) % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        dp[0][1][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
                dp[i][j] = dp[i][j] << a[i][j];
            }
        }

        if(dp[n][m][(n+m)/2]){
            cout <<"YES\n";
        }
        else cout <<"NO\n";
    }
}
















// #include <bits/stdc++.h>
// using namespace std;
// #define inout                         \
//     freopen("input.txt", "r", stdin); \
//     freopen("output.txt", "w", stdout);
// #define int long long

// signed main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int a[n][m];
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//                 cin >> a[i][j];
//         }
//         if ((m + n) % 2 == 0)
//         {
//             cout << "NO\n";
//             continue;
//         }
//         vector <vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m, {0, 0}));

//         dp[0][0].first = a[0][0];
//         dp[0][0].second = a[0][0];

//         for (int i = 1; i < n; i++) {
//             dp[i][0] = make_pair(dp[i - 1][0].first + a[i][0], dp[i - 1][0].first + a[i][0]);
//         }

//         for (int i = 1; i < m; i++) {
//             dp[0][i] = make_pair(dp[0][i - 1].first + a[0][i], dp[0][i - 1].first + a[0][i]);
//         }

//         for (int i = 1; i < n; i++) {
//             for (int j = 1; j < m; j++)
//             {
//                 int minEle = min(dp[i - 1][j].first, dp[i][j - 1].first);
//                 int maxEle = max(dp[i - 1][j].second, dp[i][j - 1].second);
//                 dp[i][j] = make_pair(minEle + a[i][j], maxEle + a[i][j]);
//             }
//         }

//         int minEle = dp[n - 1][m - 1].first;
//         int maxEle = dp[n - 1][m - 1].second;
//         if (minEle % 2 == 0 and minEle <= 0 and maxEle >= 0)
//         {
//             cout << "YES\n";
//         }
//         else
//             cout << "NO\n";
//     }
// }