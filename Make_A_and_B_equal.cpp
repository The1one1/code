#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a, b;

signed main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        a = b = vector<int>(n);
        for(auto &it: a) cin>>it;
        for(auto &it: b) cin>>it;

        int sum =0;
        int aSum=0,bSum=0,bCnt=0,aCnt=0;;

        for(int i=0;i<n;i++)
        {
            if(a[i]>b[i]){
                aSum+=abs(b[i]-a[i]);
                aCnt+=abs(b[i]-a[i]);
            }
            else if (a[i]<b[i])
            {
                bSum+=abs(b[i]-a[i]);
                bCnt+=abs(b[i]-a[i]);
            }
        }
        if(!(aSum==bSum and aCnt==bCnt))
            cout<<"-1\n" ;
        else 
            cout<<min(aSum,bSum) << "\n";
    }
    return 0;
}