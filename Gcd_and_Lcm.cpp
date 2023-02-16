#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e9 + 7;

signed main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        unordered_set<int> ps;
        for (int i = 1; i * i <= n; i++){
            if (n % i == 0){
                int x = sqrt(i);
                int y = sqrt(n / i);

                if (x * x == i){
                    ps.insert(i);
                }

                if (y * y == (n / i)){
                    ps.insert(n / i);
                }
            }
        }

        int counter = 0;
        for (auto it : ps){
            int f = n / it;
            for (int i = 1; i * i <= f; i++){
                if (f % i == 0){
                    int x = f / i;
                    int y = i;

                    int root1 = (x - 1) * it;
                    int root2 = (y - 1) * it;

                    int a1 = sqrt(root1);
                    int b1 = sqrt(root2);

                    if (sqrt(it) != __gcd(a1, b1)){
                        continue;
                    }

                    if (a1 * a1 == root1 && b1 * b1 == root2){

                        if (a1 == 0 || b1 == 0){
                            continue;
                        }

                        else if (a1 == b1){
                            counter++;
                        }
                        else{
                            counter += 2;
                        }
                    }
                }
            }
        }
        cout << counter << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int pow(int x) {
//     return x * x;
// }

// signed main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         int cnt = 0;
//         for (int a = 1; a * a < n; a++)
//         {
//             for (int b = a; b * b < n; b++)
//             {
//                 int gcd = __gcd(a, b);
//                 int lcm = a * b / gcd;
//                 int x = pow(b - a, 2) + pow(gcd + lcm, 2);
//                 if (x == n) {
//                     cnt += 2;
//                     if (a == b)
//                         cnt--;
//                 }
//             }
//         }
//         cout << cnt << endl;
//     }
// }