#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        if (s == t)
            cout << "YES" << endl;
        else if (n == 1 and s != t){
            cout << "NO\n";
        }
        else
        {
            bool flag = false;
            int i = 0, j = 0;
            while (i < n and j < n)
            {
                if (s[i] > t[j]) {
                    flag = true;
                }
                else if (t[j] == 'c') {
                    for (int k = j; k < n; k++) {
                        if (s[k] == 'a') {
                            flag = true;
                            break;
                        }
                        else if (s[k] == 'c') {
                            swap(s[k], s[i]);
                            break;
                        }
                        else if (k == n - 1) {
                            flag = true;
                        }
                    }
                }
                else if (t[j] == 'b' and s[i] == 'c') {
                    flag = true;
                }
                else if (t[j] == 'b' and s[i] == 'a') {
                    for (int k = j; k < n; k++) {
                        if (s[k] == 'c') {
                            flag = true;
                            break;
                        }
                        else if (s[k] == 'b') {
                            swap(s[k], s[i]);
                            break;
                        }
                        else if (k == n - 1){
                            flag = true;
                        }
                    }
                }
                if(flag){
                    cout << "NO\n";
                    break;
                }
                i++, j++;
            }
            if(!flag)
                cout << "YES\n";
        }
    }
}







// #include<bits/stdc++.h>
// using  namespace  std;

// #define faster  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 

// #define all(x) x.begin(),x.end()
// #define nl      '\n'
// #define mod 1000000007
// typedef long long int ll;
// typedef unsigned long long int  llu;
 
 
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         string a,b;
//         cin>>a>>b;
//         stack<char>st;
//         int ans=0;
//         int j=0;
//         int cnta=0,cntb=0,cntc=0;
//         for(int i=0;i<n;i++)
//         {
//             if(b[i]=='a')
//             {
//                 if(st.empty())
//                 {
//                     if(a[j]=='a')j++;
//                     else
//                     {
//                         ans=1;
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     if(st.top()=='a' && cntc==0)st.pop(),cnta--;
//                     else
//                     {
//                         ans=1;
//                         break;
//                     }
//                 }
 
 
//             }
//             else if(b[i]=='b')
//             {
//                 if(cntc!=0)
//                 {
//                     ans=1;
//                     break;
//                 }
//                 else if(!st.empty() && st.top()=='b')st.pop(),cntb--;
//                 else
//                 {
//                     while(j<n)
//                     {
//                         if(a[j]=='a')st.push(a[j]),cnta++;
//                         else if(a[j]=='b')
//                         {
//                             j++;
//                             break;
//                         }
//                         else
//                         {
//                             ans=1;
//                             break;
//                         }
//                         j++;
//                     }
//                 }
//             }
//             else
//             {
//                 if(cnta!=0)
//                 {
//                     ans=1;
//                     break;
//                 }
//                 if(!st.empty() && st.top()=='c')st.pop(),cntc--;
//                 else
//                 {
//                     while(j<n)
//                     {
//                         if(a[j]=='b')st.push(a[j]),cntb++;
//                         else if(a[j]=='c')
//                         {
//                             j++;
//                             break;
//                         }
//                         else
//                         {
//                             ans=1;
//                             break;
//                         }
//                         j++;
//                     }
//                 }
//             }
//         }
//         if(ans==1 || !st.empty())cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;
//     }
// }