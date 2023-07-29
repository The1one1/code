#include<bits/stdc++.h>
using namespace std;
#define int long long

/**
 * @brief This function preprocesses the input string and stores the number of 1s before each index in prefix1 vector.
 * 
 * @param n The length of the input string.
 * @param str The input binary string.
 * @param prefix1 The vector to store the number of 1s before each index.
 */
void preprocess(int n, string &str, vector<int>& prefix1) {
    for(int i = 1; i <= n; i++) {
        prefix1[i] = prefix1[i - 1] + (str[i - 1] == '1');
    }
}

/**
 * @brief This function solves the problem by processing the input queries and outputting the answer.
 * 
 */
void solve() {
    int n, m; cin >> n >> m;
    string str; cin >> str;
    vector<int> prefix1(n + 1, 0); // stores the number of 1s before each index
    preprocess(n, str, prefix1);
    vector<unordered_set<int>> v(n + 1);
    bool flag = false;
    while(m--) {
        int l, r; cin >> l >> r;
        if(str[l - 1] == '0') {
            l = upper_bound(prefix1.begin() + l, prefix1.end(), prefix1[l]) - prefix1.begin();
        }
        if(l >= r) {
            flag = true;
            continue;
        }
        int zeroCnt = (r - l + 1) - (prefix1[r] - prefix1[l - 1]);
        bool Sorted = (zeroCnt == 0);  // if all the elements are 1s in the range [l, r] then it is sorted
        if(not Sorted) {
            v[l].insert(zeroCnt);
        }
        if(Sorted) flag = true;
    }

    int ans = flag;
    for(int i = 1; i <= n; i++) {
        ans += v[i].size();
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}