#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = s.size();
        int p, k = 1; cin >> p;
        int cnt = 0;
        map<char, int> m;
        map<int, int> m2;
        for (int i = 0; i < n; i++)
        {
            if (m[s[i]] == 0)
                m[s[i]] = ((int)(s[i] - 'a') + 1);

            cnt += ((int)(s[i] - 'a') + 1);
            m2[-1 * m[s[i]]]++;
        }

        if (cnt <= p) {
            cout << s << endl;
            continue;
        }
        else {
            bool flag = false;
            for (auto &[key, value] : m2) {
                while (value--) {
                    cnt = cnt + key;
                    if (cnt <= p) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        // cout << p << endl;
        for (int i = 1; i <= n; i++)
        {
            if (m2[-1 * m[s[i-1]]] > 0)
            {
                cout << s[i - 1];
                m2[-1 * m[s[i-1]]]--;
            }
        }
        cout << endl;
    }
}