#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> xcnt(n+1, 1), ycnt(n+1, 1);
    set<int> x, y;
    for(int i = 1; i <= n; i++){
        x.insert(i);
    }
    y = x;
    while (q--)
    {
        int t, x1, y1, x2, y2;
        cin >> t;
        switch (t) {
        case 1:
            cin >> x1 >> y1;
            if(xcnt[x1] == 1){
                x.erase(x1);
            }
            if(ycnt[y1] == 1){
                y.erase(y1);
            }
            xcnt[x1]--;
            ycnt[y1]--;
            break;
        case 2:
            cin >> x1 >> y1;
            if(xcnt[x1] == 0){
                x.insert(x1);
            }
            if(ycnt[y1] == 0){
                y.insert(y1);
            }
            xcnt[x1]++;
            ycnt[y1]++;
            break;
        case 3:
            cin >> x1 >> y1 >> x2 >> y2;
            bool flag1 = true, flag2 = true;
            auto it = x.lower_bound(x1);
            if(it != x.end() and *it <= x2) flag1 = false;

            if(not flag1){
                it = lower_bound(y.begin(), y.end(), y1);
                if(it != y.end() and *it <= y2) flag2 = false;
            }

            if (flag1 or flag2)
                cout << "Yes\n";
            else
                cout << "No\n";
            break;
        }
    }
}