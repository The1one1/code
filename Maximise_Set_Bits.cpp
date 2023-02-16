#include <bits/stdc++.h>
using namespace std;
#define int long long

int fun(int x, int n)
{
    int i = 0, cnt = 0, K = x, prev_Bits_Carry = 0;
    while (x > 0)
    {
        int maxBits = x / (1 << i);
        maxBits = min(n, maxBits);
        if(((K >> i) & 1) != ((maxBits + prev_Bits_Carry)&1))
            maxBits--;
        
        x = x - (1 << i) * maxBits;
        i++;
        cnt += maxBits;
        prev_Bits_Carry = (maxBits + prev_Bits_Carry) / 2;
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k <= n)
            cout << k << endl;
        else
        cout << fun(k, n) << endl;
    }
}



// ! alternate

#include <bits/stdc++.h>
using namespace std;
#define int long long

int fun(int k, int n)
{
    int ans = 0, curr = 0;
    while(k > 0) {
        int y = min(k, n);
        if(k%2 == y%2)
            curr = y;
        else curr = y-1;
        
        k = (k - curr)/2;
        ans += curr;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k <= n)
            cout << k << endl;
        else
        cout << fun(k, n) << endl;
    }
}