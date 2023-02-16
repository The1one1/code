#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> v(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++){
            cin >> v[i];
            m[v[i]]++;
        }

        if (n % 2){
            cout << "NO\n";
            continue;
        }
        bool flag = true;
        for (auto &[key, value] : m){
            if (value > n / 2){
                cout << "NO\n";
                flag = false;
            }
        }

        if (flag){
            sort(v.begin(), v.end());
            vector<int> a;
            int i = 0, j = n / 2;
            while (i < j and j < n)
            {
                a.push_back(v[i]);
                a.push_back(v[j]);
                i++, j++;
            }

            for (int i = 0; i < n; i++)
            {
                if (i % 2 == 1 and a[i % n] > a[(i + 1) % n])                
                    continue;
                else if (i % 2 == 0 and a[i % n] < a[(i + 1) % n])
                    continue;
                else
                {
                    cout << "NO\n";
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                cout << "YES\n";
                for (auto &it : a)
                    cout << it << " ";
                cout << endl;
            }
        }
    }
}