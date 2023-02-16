#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a, lazy, tree;

void build(int ind, int low, int high)
{
    if (high == low){
        tree[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

void lazyPointUpdate(int ind, int low, int high, int pos, int val) {
    if (lazy[ind] != 0) {
        tree[ind] = (high - low + 1) * lazy[ind];
        if (high != low)
        {
            lazy[2 * ind + 1] = lazy[ind];
            lazy[2 * ind + 2] = lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (high < pos or low > pos)
        return;

    if (low == high) {
        if (low == pos)
            tree[ind] = val;
        return;
    }

    int mid = (low + high) / 2;
    lazyPointUpdate(2 * ind + 1, low, mid, pos, val);
    lazyPointUpdate(2 * ind + 2, mid + 1, high, pos, val);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

void lazyRangeUpdate(int ind, int low, int high, int l, int r, int val) {
    if (lazy[ind] != 0)
    {
        tree[ind] = (high - low + 1) * lazy[ind];
        if (high != low) {
            lazy[2 * ind + 1] = lazy[ind];
            lazy[2 * ind + 2] = lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (high < l or low > r and low > high)
        return;
    if (low >= l and high <= r) {
        tree[ind] = (high - low + 1) * val;
        if (high != low) {
            lazy[2 * ind + 1] = val;
            lazy[2 * ind + 2] = val;
        }
        return;
    }
    int mid = (low + high) / 2;
    lazyRangeUpdate(2 * ind + 1, low, mid, l, r, val);
    lazyRangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

signed main()
{
    int n, q;
    cin >> n >> q;
    a = vector<int>(n);
    tree = lazy = vector<int>(4 * n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n - 1);
    while (q--)
    {
        int t, i, x;
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> i >> x;
            lazyPointUpdate(0, 0, n - 1, i - 1, x);
            cout << tree[0] << endl;
            break;

        case 2:
            cin >> x;
            lazyRangeUpdate(0, 0, n - 1, 0, n - 1, x);
            cout << tree[0] << endl;
            break;
        }
    }
}





// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     int n, q;
//     cin >> n >> q;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     int sum = accumulate(a.begin(), a.end(), 0ll);
//     vector<int> v(n+1);
//     int idx = 0ll, value = 0ll;
//     while (q--)
//     {
//         int t, i, x;
//         cin >> t;
//         switch (t)
//         {
//         case 1:
//             cin >> i >> x;
//             if(v[i] < idx){
//                 a[i-1] = value;
//                 v[i] = idx;
//             }
//             sum = sum - a[i - 1] + x;
//             a[i-1] = x;
//             cout << sum << "\n";
//             break;

//         case 2:
//             cin >> x;
//             sum = n * x;
//             idx++;
//             value = x;
//             cout << sum << "\n";
//             break;
//         }
//     }
// }