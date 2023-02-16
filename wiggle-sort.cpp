#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    vector<int> a(t);
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }

    for(int i = 0; i < t- 1; i++){
        if(i % 2 == 1 and a[i] > a[i+1]){
            swap(a[i], a[i+1]);
        }
        else if(i % 2 == 0 and a[i] < a[i+1]){
            swap(a[i], a[i+1]);
        }
    }
    for_each(a.begin(), a.end(), [&](auto it){ cout << x << "\n"; });
}