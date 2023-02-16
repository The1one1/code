#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n] = {0};
    int q; cin >> q;

    while(q--)
    {
        int x, y ,z;           
        cin >> x >> y >> z;
        a[x] = z;
        if(y+1 < n)
        {
            a[y+1] = -1 * z;
        }
    }
    for(int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i-1];
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] <<" ";
    }
}