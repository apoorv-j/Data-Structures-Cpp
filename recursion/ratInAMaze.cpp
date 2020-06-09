#include <bits/stdc++.h>
using namespace std;

void moveRat(char **arr, bool **store, int i, int j, int n, int m)
{
    store[i][j] = 1;
    if (i == n and j == m)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (store[i][j])
                    cout << "(" << i << "," << j << ") ";
            }
        }
        cout << endl;
        store[i][j] = 0;
        return;
    }

    //move right
    if (j < m and arr[i][j + 1] == 'O')
    {
        moveRat(arr, store, i, j + 1, n, m);
    }

    //move down
    if (i < n and arr[i + 1][j] == 'O')
    {
        moveRat(arr, store, i + 1, j, n, m);
    }

    //move left
    if (i > 0 and arr[i - 1][j] == '0')
    {
        moveRat(arr, store, i - 1, j, n, m);
    }
    //move up
    if (j > 0 and arr[i][j - 1] == '0')
    {
        moveRat(arr, store, i, j - 1, n, m);
    }
    store[i][j] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    char **arr = new char *[n];
    bool *store[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        store[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            store[i][j] = 0;
        }
    }

    moveRat(arr, store, 0, 0, n - 1, m - 1);

    return 0;
}