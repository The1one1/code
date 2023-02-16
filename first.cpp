/*
                         /\   
                        /''\  
                       /''''\ 
                      (0)==(0)
                     /__||||__\
                    /          \
                   /            \
*/






#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(i, a, n) for (int i = a; i < (n); i++)
#define fm(i, a, b) for (int i = (a); i >= b; i--)
using namespace std;
ll ans = 0;

void solve(vector<vector<ll>> &tree, ll i, vector<ll> &temp, vector<pair<ll,ll>> &v){
    if(tree[i].size() == 0){
        temp[i] = v[i].second;
        ans++;
        return;
    }
    ll ans1 = 0;
    for(ll it : tree[i]){
        solve(tree, it, temp, v);
        ans1 += temp[it];
    }
    if(ans1 >= v[i].second){ 
        temp[i] = v[i].second;
        return;
    }
    if(ans1 >= v[i].first){
        temp[i] = ans1;
        return;
    }
    ans++;
    temp[i] = v[i].second;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ans = 0;
        ll n; cin>>n;
        vector<vector<ll>> tree(n+1);
        f(i,2,n+1){
            ll x; cin>>x;
            tree[x].pb(i);
        }
        vector<pair<ll,ll>> v(n+1);
        f(i,1,n+1){
            ll x, y; cin>>x>>y;
            v[i].first = x;
            v[i].second = y;
        }
        vector<ll> temp(n+1, 0);
        solve(tree, 1, temp, v);
        cout<<ans<<"\n";
    }
    return 0;
}