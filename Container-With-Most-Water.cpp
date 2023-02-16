#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    int i = 0, j = n-1, k = n-1;
    while(i <= j){
        if(a[i] < a[j]){
            b[k] = a[j] * a[j];
            j--;
            k--;
        }
        else if(a[i] >= a[j]){
            b[k] = a[i] * a[i];
            k--;
            i++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
    }
}