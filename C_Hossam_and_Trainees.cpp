#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<bool> isPrime(1e5 + 1, 1);

void sieve() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < isPrime.size(); i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    sieve();
    vector<int> PrimeNo;
    for(int i = 2; i < isPrime.size(); i++) {
        if(isPrime[i]) PrimeNo.push_back(i);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_map<int, bool> m;
        for(int i = 0; i < n; i++) {
            for(auto &prime: PrimeNo) {
                if(prime * prime > a[i]) {
                    break;
                }
                if(a[i] % prime == 0) {
                    if(m[prime]) {
                        cout << "YES\n";
                        goto last;
                    }
                    m[prime] = 1;
                    while(a[i] % prime == 0) {
                        a[i] = a[i] / prime;
                    }
                }
            }
            if(a[i] > 1 and m[a[i]]) {
                cout << "YES\n";
                goto last;
            }
            else if(a[i] > 1) m[a[i]] =  1;
        }
        cout << "NO\n";
        last:;
    }
}