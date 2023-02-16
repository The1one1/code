#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int val[3] = {(int)(1e9 + 7)}, cnt[3] = {0};
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < 3; j++) {
            if (arr[i] == val[j]) {
                cnt[j]++;
                flag = true;
                break;
            }
        }
        if (!flag) {
            for (int j = 0; j < 3; j++) {
                if (cnt[j] == 0) {
                    val[j] = arr[i];
                    cnt[j]++;
                    break;
                }
            }
        }
        if (all_of(cnt, cnt + 3, [](int x){ return x >= 1; })) {
            cnt[0]--;
            cnt[1]--;
            cnt[2]--;
        }
    }

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val[0])
            cnt[0]++;
        else if (arr[i] == val[1])
            cnt[1]++;
        else if (arr[i] == val[2])
            cnt[2]++;
    }

    vector<int> a;
    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] > n / 3)
            a.push_back(val[i]);
    }
    cout << "[";
    for_each(a.begin(), a.end() - 1, [&](auto it)
             { cout << it << ", "; });
    cout << a.back() << "]";
}