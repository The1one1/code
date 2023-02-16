#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }

        int oddcnt = 0, evencnt = 0;
        for(auto &it: m)
        {
            if(it.second % 2 == 0)
            {
                evencnt++;
            }
            else oddcnt++;
        }
        cout << oddcnt + 2 * (evencnt/(int)2) << endl;
    }
}