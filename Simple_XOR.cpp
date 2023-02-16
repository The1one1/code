#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        if(l%2 == 0 ){
            cout << l << " "<<l+1<<" "<<l+2<<" "<<l+3<<endl;
        }
        else if(l%2 == 1 and l+4<=r){
            cout << l+1<<" "<<l+2<<" "<<l+3<<" "<<l+4<<endl;
        }
        else cout <<"-1\n";
    }
}