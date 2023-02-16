#include <bits/stdc++.h>
using namespace std;
#define int long long

int fun(int n, string &s)
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            if (s[i] == '1')
                sum += 11;
        }
        else if (s[i] == '1' and s[i + 1] == '0')
            sum += 10;
        else
            sum += 1;
    }
    return sum;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int oneCnt = 0, leftZ = 0, rightZ = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                oneCnt++;
                flag = false;
            }
            else if (s[i] == '0' and flag)
                leftZ++;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                rightZ++;
            else
                break;
        }

        if (oneCnt == 0)
            cout << 0 << endl;

        else if (oneCnt == 1)
        {
            if (s.size() == 1)
                cout << 1 << endl;

            else if (rightZ <= k)
                cout << 1 << endl;

            else if (leftZ <= k)
                cout << 10 << endl;

            else
                cout << fun(n, s) << endl;
        }
        else
        {
            if (rightZ <= k)
            {
                k = k - rightZ;
                swap(s[n - 1], s[n - rightZ - 1]);
            }
            if (leftZ <= k)
                swap(s[0], s[leftZ]);

            cout << fun(n, s) << endl;
        }
    }
}