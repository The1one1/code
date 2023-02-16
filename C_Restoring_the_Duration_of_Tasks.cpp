#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        queue<int> s, f;
        for(int i = 0; i < n; i++){
            int x; cin >> x; 
            s.push(x);
        }

        for(int i = 0; i < n; i++){
            int x; cin >> x; 
            f.push(x);
        }

        vector<int> v;
        int x = 0;
        while(not s.empty()){
            int s1 = s.front();
            s.pop();
            int q1 = f.front();
            f.pop();

            x = max(x, s1);
            int y = q1 - x;
            if(y >= 0){
                v.push_back(y);
                x += y;
            }
            else{
                v.push_back(0);
            }
        }

        for(auto &it: v){
            cout <<it<<" ";
        }cout<<endl;
    }
}