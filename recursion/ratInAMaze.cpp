#include <bits/stdc++.h>
using namespace std;

void printAllPaths(char **arr, bool **store, int i, int j, int n, int m)
{
    store[i][j] = 1;
    if (i == n and j == m)
    {
        cout << endl;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << store[i][j] << " ";
            }
            cout << endl;
        }
        store[i][j] = 0;
        return;
    }
    //move right
    if (j < m and arr[i][j + 1] == 'O')
    {
        printAllPaths(arr, store, i, j + 1, n, m);
    }
    //move down
    if (i < n and arr[i + 1][j] == 'O')
    {
        printAllPaths(arr, store, i + 1, j, n, m);
    }
    //move left
    if (i > 0 and arr[i - 1][j] == '0')
    {
        printAllPaths(arr, store, i - 1, j, n, m);
    }
    //move up
    if (j > 0 and arr[i][j - 1] == '0')
    {
        printAllPaths(arr, store, i, j - 1, n, m);
    }
    store[i][j] = 0;
}

bool moveRat(char **arr, bool **store, int i, int j, int n, int m)
{
    store[i][j] = 1;
    if (i == n and j == m)
    {
        // cout << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << store[i][j] << " ";
            }
            cout << endl;
        }
        store[i][j] = 0;
        return true;
    }
    bool rp = false;
    //move right
    if (j < m and arr[i][j + 1] == 'O')
    {
        if (moveRat(arr, store, i, j + 1, n, m))
            return true;
    }
    //move down
    if (i < n and arr[i + 1][j] == 'O')
    {
        if (moveRat(arr, store, i + 1, j, n, m))
            return true;
    }
    //move left
    if (i > 0 and arr[i - 1][j] == '0')
    {
        if (moveRat(arr, store, i - 1, j, n, m))
            return true;
    }
    //move up
    if (j > 0 and arr[i][j - 1] == '0')
    {
        if (moveRat(arr, store, i, j - 1, n, m))
            return true;
    }
    store[i][j] = 0;
    return false;
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

    if (!moveRat(arr, store, 0, 0, n - 1, m - 1))
        cout << -1;

    return 0;
}