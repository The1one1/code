#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >>n;
        string a, b; cin >> a >> b;

        int cnt = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                if(m.find(b[i]) == m.end()){
                    m[b[i]]++;
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
}