#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int A, vector<vector<int>> &B)
{
    vector<int> X(A + 1, 0), Y(A + 1, 0), cnt(A + 2), ans;
    int k = 0;
    while (k < B.size())
    {
        switch (B[k][0])
        {
        case 1:
            cnt[B[k][1]]++, cnt[B[k][2] + 1]--;
            break;

        case 2:
            for (int i = 1; i <= A; i++)
            {
                cnt[i] += cnt[i - 1];
                X[i] = (X[i] + cnt[i]) % 2;
                Y[i] = Y[i] + (X[i] % 2) * B[k][1];
            }
            fill(cnt.begin(), cnt.end(), 0);
            break;

        case 3:
            ans.push_back(Y[B[k][1]]);
            break;
        }
        k++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> B = {{1, 1, 7}, {2, 4, 0}, {1, 2, 5}, {3, 5, 0}, {2, 6, 0}, {1, 4, 4}, {2, 4, 0}, {3, 4, 0}};

    for (auto it : solve(7, B))
    {
        cout << it << " ";
    }
    cout << endl;
}