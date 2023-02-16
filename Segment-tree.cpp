#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int tree[4 * 100000], lazy[4 * 100000];

void Build(int ind, int low, int high){
    if(low == high){
        tree[ind] = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    Build(2*ind + 1, low , mid);
    Build(2*ind + 2, mid + 1, high);
    tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
}

int query(int idx, int low, int high, int l, int r){
    if(low >= l and high <= r){
        return tree[idx];
    }
    if(high < l or low > r){
        return INT_MIN;
    }
    int left = query(2*idx + 1, low, (low + high) / 2, l, r);
    int right = query(2*idx + 2, (low + high) / 2 + 1, high, l, r);
    return (left + right);
}

void pointUpdate(int ind, int low, int high, int pos, int val){
    if(low == high){
        tree[ind] = val;
        return;
    }
    int mid = (low + high)/2;
    if(pos <= mid) pointUpdate(2*ind + 1, low, mid, pos, val);
    else pointUpdate(2*ind + 2, mid + 1, high, pos, val);
    tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
}

void lazyRangeUpdate(int ind, int low, int high, int l, int r, int val){
    if(lazy[ind] != 0){
        tree[ind] += (high - low + 1) * lazy[ind];
        if(high != low){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(high < l or low < r){
        return;
    }
    if(low >= l and high <= r){
        tree[ind] += (high - low + 1) * val;
        if(high != low){
            lazy[2*ind + 1] += val;
            lazy[2*ind + 2] += val;
        }
        return;
    }
    int mid = (low + high)/2;
    lazyRangeUpdate(2*ind+1, low, mid, l, r, val);
    lazyRangeUpdate(2*ind + 2, mod + 1, high, l, r, val);
    tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
}

int lazyRangeQuery(int ind, int low, int high, int l, int r){
    if(lazy[ind] != 0){
        tree[ind] += (high - low + 1 ) * lazy[ind];
        if(high != low){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(high < l or low > r or low > high){
        return 0;
    }
    if(low >= l and high <= r){
        return tree[ind];
    }
    int left = lazyRangeQuery(2*ind + 1, low, (low + high) / 2, l, r);
    int right = lazyRangeQuery(2*ind + 2, (low + high) / 2 + 1, high, l, r);
    return left + right;
}

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Build(0, 0, n-1);
    // pointUpdate(0, 0, n-1, 3, 25);
    // int q; cin >> q;
    // while(q--){
    //     int l, r; cin >> l >> r;
    //     cout << query(0, 0, n-1, l, r) << endl;
    // }
    lazyRangeUpdate(0, 0, n-1, 3, 5, 12);
    cout << lazyRangeQuery(0, 0, n-1, 3, 5) << endl;
}