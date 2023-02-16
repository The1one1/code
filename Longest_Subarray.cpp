#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> v;

bool check(int mid, vector<int> &a)
{
    int l = 0, r = mid, n = a.size();
    while (l < r and r <= a.size()) {
        bitset<32> bits1, bits2;
        for (int i = 0; i < 32; i++)
        {
            if (l == 0)
                bits1[i] = (v[r - 1][i] > 0 ? 1 : 0);
            else
            {
                bits1[i] = (v[r - 1][i] - v[l - 1][i] > 0 ? 1 : 0);
                bits2[i] = v[l - 1][i];
            }
        }

        for (int i = 0; i < 32; i++){
            bits2[i] = bits2[i] | (v[n - 1][i] - v[r - 1][i] > 0 ? 1 : 0);
        }
        l++, r++;
        if (bits1 == bits2) {
            return true;
        }
    }
    return false;
}

int binarySearch(vector<int> &a)
{
    int low = 0, high = a.size();
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (check(mid, a))
            low = mid;
        else
            high = mid;
    }
    if (check(high, a))
        return high;
    else if (check(low, a))
        return low;
    else
        return -1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        v = vector<vector<int>>(n, vector<int>(32, 0));
        for (auto &it : a)
            cin >> it;

        for (int i = 0; i < n; i++)
        {
            bitset<32> bits = a[i];
            for (int j = 0; j < 32; j++)
            {
                if (bits[j])
                    v[i][j]++;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
                v[i][j] += v[i - 1][j];
        }

        cout << binarySearch(a) << endl;
    }
}