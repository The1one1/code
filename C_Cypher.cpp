#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> digit(n);
        for(int i = 0; i < n; i++) cin >> digit[i];
        int j = 0;
        while(j < n) {
            int y; cin >> y;
            while(y--){
                char c; cin >> c;
                if(c == 'U') {
                    digit[j] -= 1;
                    if(digit[j] < 0) digit[j] = 9;
                }
                else {
                    digit[j] += 1;
                    digit[j] = digit[j] % 10;
                }
            }
            j++;
        }
        for_each(digit.begin(), digit.end(), [&](auto it){ cout << it << " ";}); cout << endl;
    }
}