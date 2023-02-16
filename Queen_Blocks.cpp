#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;

void fun1(int a, int b)
{
    matrix[a + 1][b + 2] = 2;
    matrix[a + 1][b - 2] = 2;
    matrix[a - 1][b + 2] = 2;
    matrix[a - 1][b - 2] = 2;
}

void fun2(int a, int b)
{
    matrix[a + 1][b + 2] = 2;
    matrix[a - 1][b + 2] = 2;
}

void fun3(int a, int b)
{
    matrix[a + 1][b - 2] = 2;
    matrix[a - 1][b - 2] = 2;
}

void fun()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        matrix = vector<vector<int>>(8, vector<int>(8, 0));
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                matrix[i][j] = 0;

        int x, y;
        cin >> x >> y;
        int a = x - 1;
        int b = y - 1;
        matrix[a][b] = 1;
        
        if (b > 2 && b < 6)
        {
            fun1(a, b);
        }
        else if (b <= 2)
        {
            fun2(a, b);
        }
        else if (b >= 6)
        {
            fun3(a, b);
        }

        fun();
    }
}