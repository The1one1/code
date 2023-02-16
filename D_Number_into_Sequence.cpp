#include<bits/stdc++.h>
using namespace std;
#define int long long

void fact(int n, map<int, int> &m) {

    while(n % 2 == 0) {
        m[2]++;
        n = n / 2;
    }

    for(int i = 3; i * i <= n; i += 2) {
        while(n % i == 0) {
            n = n / i;
            m[i]++;
        }
    }
    if(n > 2) {
        m[n]++;
    }
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        map<int, int> m;
        fact(n, m);

        int N = 0, maxFreq = 0;
        for(auto &it: m) {
            if(it.second >= maxFreq) {
                N = it.first;
                maxFreq = it.second;
            }
        }

        cout << maxFreq <<endl;
        while(maxFreq > 0) {
            if(maxFreq == 1) {
                cout << n;
                break;
            }
            cout << N << " ";
            n = n/N; 
            maxFreq--;
        }
        cout << endl;
    }
}