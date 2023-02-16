#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            while(x % 2 == 0){
                v[i]++;
                x = x / 2;
            }
        }

        int min_cnt = *min_element(v.begin(), v.end());
        if(min_cnt == 0)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(v[i] != 0){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        else {
            cout << min_cnt + n - 1 << endl;
        }
    }
}