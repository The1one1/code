#include <bits/stdc++.h>
using namespace std;
#define inout                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define int long long

// void fun(int diff, int dest){
//     diff = diff / 2;
//     for(int i  = 1; i <= dest; i++){
//         if(i == diff){
//             cout << -1*i << " ";
//         }
//         else cout << i <<" ";
//     }
// }

signed main()
{
    int dest; cin >> dest;

    int currPos = (int)sqrt(2 * dest);
    if ((2 * dest) != currPos * currPos) {
        currPos++;
    }
    int jumps = currPos;
    currPos = (currPos * (currPos + 1)) / 2;

    int diff = currPos - dest;
    if (diff % 2 == 0) {
        cout << jumps;
    }
    else {
        diff += (++jumps);
        if (diff % 2 == 0) {
            cout << jumps;
        }
        else {
            cout << ++jumps;
        }
    }
}