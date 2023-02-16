#include<bits/stdc++.h>
using namespace std;
#define inout freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define int long long

signed main(){
    string str; cin >> str;
    int n = str.size();
    int  pre = 0, maxInd = 0;
    unordered_map<char, int> m;
    for(int i = 0; i < str.size(); i++) { 
        m[str[i]] =  i;
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        maxInd = max(maxInd, m[str[i]]);
        if(i == maxInd) {
            v.push_back(maxInd - pre + 1);
            pre = maxInd + 1;
        }
    }
    for_each(v.begin(), v.end(), [&](auto it){ cout << it << " ";});
}







// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     string str; cin >> str;
//     int n = str.size();
//     int y = 0, x = n-1;
//     vector<int> v;
//     while(y < n) 
//     {
//         for(int i = y; i <= x; i++) 
//         {
//             for(int j = n - 1; j >= i; j--) 
//             {
//                 if(str[i] == str[j]) 
//                 {
//                     x = j;
//                     if(j == n - 1) {
//                         goto last;
//                     }
//                     break;
//                 }
//                 else if(x != n - 1 and j <= x) {
//                     break;
//                 }
//             }
//         }
//         last:
//         v.push_back(x - y + 1);
//         y = x + 1;
//         x = n - 1;
//     }
//     for_each(v.begin(), v.end(), [&](auto it){ cout << it << " ";});
// }