#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","max_j",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        int ans = INT_MIN, max_i = 0, max_j = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int x; cin >> x;
                if(x > ans){
                    ans = x;
                    max_i = i, max_j = j;
                }
            }
        }
        int x = max(max_i + 1, n - max_i);
        int y = max(max_j + 1, m - max_j);
        cout << x * y << endl;
    }
}