#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    long long zero = 0, one = 0, ret = s.size();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            zero++;
        else
            one++;
    }
    long long z = 0, o = one, j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j < s.size() && z < o)
        {
            if (s[j] == '0')
            {
                z++;
            }
            else
            {
                o--;
            }
            j++;
        }
        ret = min(ret, max(z, o));
        if (s[i] == '0')
            z--;
        else
            o++;
    }
    cout << ret << endl;
}

int main()
{
    int n = 1, i = 0;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// bool isPossible(int mid, int _0cnt, int _1cnt, string &str, vector<int> &prefixZeroSum, vector<int> &suffixZeroSum){
//     int leftZeros = _0cnt;
//     for(int i = 0; i <= mid; i++)
//     {
//         leftZeros = min(leftZeros, _0cnt - prefixZeroSum[i] - suffixZeroSum[mid - i]);
//     }
//     return leftZeros <= mid;
// }

// signed main()
// {
//     int t; cin >> t;
//     while (t--) {
//         string str; cin >> str;
//         vector<int> prefixZeroSum, suffixZeroSum;

//         int cnt = 0;
//         for (int i = 0; i < str.size(); i++) {
//             if (str[i] == '0')
//                 cnt++;
//             else if (str[i] == '1') {
//                 prefixZeroSum.push_back(cnt);
//             }
//         }
//         prefixZeroSum.push_back(cnt);
//         cnt = 0;
//         for (int i = str.size() - 1; i > 0; i--) {
//             if (str[i] == '0')
//                 cnt++;
//             else if (str[i] == '1') {
//                 suffixZeroSum.push_back(cnt);
//             }
//         }
//         suffixZeroSum.push_back(cnt);

//         int _0cnt = count(str.begin(), str.end(), '0');
//         int _1cnt = count(str.begin(), str.end(), '1');

//         int ans = max(_0cnt, _1cnt);
//         int low = 0, high = _1cnt;
//         while(low <= high)
//         {
//             int mid = (low + high)/2;
//             if(isPossible(mid, _0cnt, _1cnt, str, prefixZeroSum, suffixZeroSum))
//             {
//                 ans = mid;
//                 high = mid + 1;
//             }
//             else low = mid + 1;
//         }
//         cout << ans << endl;
//     }
// }