#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string str; cin >> str;
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[str[i]]++;
        }

        if(mp.size() == 1) {
            cout << str << endl;
        }
        else {
            int firstChar = str[0];
            for(auto &it: mp) {
                if(it.first < firstChar) {
                    for(int i = n - 1; i >= 0; i--) {
                        if(str[i] == it.first) {
                            cout << it.first << str.substr(0, i) << str.substr(i + 1, n) << endl;
                            goto last;
                        }
                    }
                }
                else if (it.first == firstChar and it.second > 1) {
                    for(int i = n-1; i >= 0; --i) {
                        if(str[i] == it.first) {
                            cout << it.first << str.substr(0, i) << str.substr(i + 1, n) <<  endl;
                            goto last;
                        }
                    }
                }
                else {
                    cout << str << endl;
                    goto last;
                }
            }
            last:;
        }
    }
}