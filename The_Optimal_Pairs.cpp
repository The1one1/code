#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i * i <= n; i++)
        {
            if ((n - i) % i == 0)
            {
                int a = i, b = n - i;
                if (a != b)
                    cnt += 2;
                else
                    cnt++;

                int c = n / i, d = n - c;
                if (min(a, b) != min(c, d) and min(c, d) != 0){
                    if (c != d) 
                        cnt += 2;
                    else
                        cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}