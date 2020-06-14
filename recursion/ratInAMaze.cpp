#include <bits/stdc++.h>
using namespace std;

bool moveRat(char **arr, bool **store, int i, int j, int n, int m)
{
    if (i == n - 1 and j == m - 1)
    {
        store[i][j] = 1;
        // cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << store[i][j] << " ";
            }
            cout << endl;
        }
        store[i][j] = 0;
        return true;
        // to print all paths
        // return false
    }

    if (i < 0 or j < 0 or i > (n - 1) or j > (m - 1) or arr[i][j] == 'X' or store[i][j] == 1)
        return false;

    store[i][j] = 1;

    //move right
    if (moveRat(arr, store, i, j + 1, n, m))
        return true;

    //move down
    if (moveRat(arr, store, i + 1, j, n, m))
        return true;

    //move up
    if (moveRat(arr, store, i - 1, j, n, m))
        return true;

    //move left
    if (moveRat(arr, store, i, j - 1, n, m))
        return true;

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

    if (!moveRat(arr, store, 0, 0, n, m))
        cout << "NO PATH FOUND";

    return 0;
}