#include<bits/stdc++.h>
using namespace std;
#define int long long

bool fun(int i, int j, vector<vector<bool>> v, int sum) {
    int m = v[0].size();
    while(sum) {
        v[i][j] = 0;
        sum--;
        if(sum == 0 ) return true;
        if(i == 0 and v[i + 1][j]) {
            i++;
        }
        else if(i == 0 and j + 1 < m and v[i][j+1]){
            j++; 
        }
        else if(i == 1 and v[i - 1][j]) {
            i--;
        }
        else if(i == 1 and j + 1 < m and v[i][j + 1]) {
            j++;
        }
        else return false;
    }
    if(sum == 0) return true;
    return false;
}

signed main() {
    int t; cin >> t;
    while(t--) {
        int m; cin >> m;
        vector<vector<bool>> v(2, vector<bool>(m, 1));
        int sum = 2 * m;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < m; j++) {
                char c; cin >> c;
                if(c == 'W') {
                    v[i][j] = 0;
                    sum--;
                }
            }
        }

        bool flag = false;
        if(v[0][0]) {
            flag = fun(0, 0, v, sum);
        }
        if(v[1][0]) {
            flag = flag | fun(1, 0, v, sum);
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}