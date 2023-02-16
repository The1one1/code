#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

signed main(){
    #ifndef ONLINE_JUDGE
    inout
    #endif

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m; 
        vector<vector<int> > a(n, vector<int> (m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }

        int max_sum = INT_MIN;

        vector<vector<int> > v(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            v[0][i] = a[0][i];
            if(v[0][i] > max_sum) max_sum = v[0][i];
        }

        vector<vector<int> > h(n, vector<int> (m));
        vector<vector<int> > d(n, vector<int> (m));

        for(int i = 0; i < m; i++){
            h[0][i] = a[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i-1 >= 0 and j-1 >= 0){
                    h[i][j] = h[i-1][j-1];
                }
                h[i][j] += a[i][j];
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i+1 < n and j - 1 >=0 ){
                    d[i][j] = d[i+1][j-1] ;
                }
                d[i][j] += a[i][j];
            }
        }   

        int max_sum_h = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(max_sum_h < (h[i][j] + d[i][j] - a[i][j])){
                    max_sum_h = h[i][j] + d[i][j] - a[i][j];
                }
            }
        }
        cout << max_sum_h << endl;
    }
}