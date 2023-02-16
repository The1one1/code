#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        char a[9][9];
        for(int i = 1; i < 9; i++){
            for(int j = 1; j < 9; j++){
                cin >> a[i][j];
            }
        }

        for(int i = 2; i < 8; i++){
            for(int j = 2; j < 8; j++){
                if(a[i][j] == '#' and a[i-1][j-1] == '#' and a[i+1][j-1] == '#' and a[i-1][j+1] == '#' and a[i+1][j+1] == '#'){
                    cout << i <<" "<< j << endl;
                    goto last;
                }
            }
        }
        last:;
    }
}