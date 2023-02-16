#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int n, w, l;
vector<int> h, r;

bool check(int mid)
{
    // if 'sum' is 'unsigned long long' then it is not possible to get the sum less than 0
    long long sum = w;
    for (int i = 0; i < n; i++)
    {
        if (h[i] + r[i] * mid >= l)
        {
            long long ans = r[i] * mid;
            // maximum wood possible is 10^18(constraint), so once we reach 10^18, we can stop and return true
            // on overflow, variable 'ans' will be negative 
            if (ans < 0)
                return true;

            sum -= (h[i] + ans);
        }
        if (sum <= 0)
            return true;
    }
    return 0;
}

signed main()
{
    cin >> n >> w >> l;
    r = h = vector<int>(n, 0);

    for (int i = 0; i < n; i++)
        cin >> h[i] >> r[i];

    int low = 0ull, high = (int)1e18 + 1ull;

    while (high - low > 1)
    {
        int mid = low + (high - low) / 2ull;

        if (check(mid))
            high = mid;
        else
            low = mid + 1ull;
    }
    if (check(low))
        cout << (int)low << endl;
    else
        cout << (int)high << endl;
}