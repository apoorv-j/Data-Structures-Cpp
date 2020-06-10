#include <bits/stdc++.h>
using namespace std;

bool isPossible(int **arr, int i, int j, int n, int num)
{

    for (int k = 0; k < n; k++)
    {
        if (arr[i][k] == num or arr[k][j] == num)
            return false;
    }
    int root_n = sqrt(n);
    int grid_i = (i / root_n) * root_n;
    int grid_j = (j / root_n) * root_n;

    for (int si = grid_i; si < grid_i + root_n; si++)
    {
        for (int sj = grid_j; sj < grid_j + root_n; sj++)
        {
            if (arr[si][sj] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int **arr, int i, int j, int n)
{
    if (i == n and j == n)
    {
        // cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if (j == n)
    {
        j = 0;
        i += 1;
    }

    if (arr[i][j] != 0)
        return solveSudoku(arr, i, j + 1, n);

    for (int num = 1; num <= n; num++)
    {
        if (isPossible(arr, i, j, n, num))
        {
            arr[i][j] = num;
            if (solveSudoku(arr, i, j + 1, n))
                return true;
            else
                arr[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    solveSudoku(arr, 0, 0, n);
    return 0;
}