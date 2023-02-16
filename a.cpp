// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// const int N = 1e9 + 7;
// vector<int> adj[100005];
// vector<int> height[100005];
// int nod[100005];

// void dfs(int i, int p, int arr[], int h) {
// 	arr[i] = h;
// 	for (auto it : adj[i]) {
// 		if (it == p)
// 			continue;
// 		dfs(it, i, arr, h + 1);
// 	}
// }

// signed main()
// {
// 	int t; cin >> t;
// 	while (t--) {
// 		int n, k;
// 		cin >> n >> k;
// 		for (int i = 0; i <= n; i++) {
// 			adj[i].clear();
// 			height[i].clear();
// 			nod[i] = 0;
// 		}

// 		vector<int> v;
// 		for (int i = 1; i < n; i++) {
// 			int x;
// 			cin >> x;
// 			v.push_back(x);
// 		}
// 		int x = 2;
// 		for (auto it : v) {
// 			adj[it].push_back(x);
// 			adj[x].push_back(it);
// 			x++;
// 		}
// 		int lev[n + 1] = {0};
// 		dfs(1, 0, lev, 1);

// 		int maxi = 0;
// 		for (int i = 1; i <= n; i++) {
// 			height[lev[i]].push_back(i);
// 			cout << lev[i];
// 			maxi = max(maxi, lev[i]);
// 		}

// 		int parent[n + 1];
// 		// fill(parent, parent + n + 1, 0);
// 		for (int i = 0; i <= n; i++)
// 			parent[i] = 0;

// 		while (maxi > 0) {
// 			for (auto i : height[maxi]) {
// 				if (k > 0) {
// 					if (parent[i] == 0) {
// 						parent[i] = 1;
// 						parent[v[i]] = parent[v[i]] ^ parent[i];
// 						nod[i] = 1;
// 					}

// 					else if (parent[i] == 1) {
// 						nod[i] = 0;
// 						parent[v[i]] = parent[v[i]] ^ parent[i];
// 					}
// 					k--;
// 				}

// 				else {
// 					if (parent[i] == 0) {
// 						parent[i] = 0;
// 						parent[v[i]] ^= parent[i];
// 						nod[i] = 0;
// 					}

// 					else if (parent[i] == 1) {
// 						nod[i] = 1;
// 						parent[i] = 0;
// 						parent[v[i]] ^= parent[i];
// 					}
// 				}
// 			}
// 			maxi--;
// 		}

// 		for (int i = 1; i <= n; i++)
// 			cout << nod[i];

// 		cout << endl;
// 	}
// }

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cout << "Case #" << q + 1 << ":"<< " ";
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            brr[i] = arr[i];
        sort(brr, brr + n);
        for (int i = 0; i < n; ++i)
        {
            auto yoman = upper_bound(brr, brr + n, arr[i] * 2) - brr;
            yoman--;
            if (brr[yoman] == arr[i])
                yoman--;
            if (yoman >= 0)
                cout << brr[yoman] << " ";
            else
                cout << "-1"
                     << " ";
        }
        cout << endl;
    }

    return 0;
}