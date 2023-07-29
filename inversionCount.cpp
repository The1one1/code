#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> bit;
void update(int i, int x, int n) {
    for (; i <= n; i += (i & -i)) bit[i] += x;
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= (i & -i)) sum += bit[i];
    return sum;
}

signed main(){
    int n; cin >> n;
    int ans = 0;

    bit = vector<int> (10, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(x, 1, 10);
        ans += (query(10) - query(x));
    }
    cout << ans << endl;
}