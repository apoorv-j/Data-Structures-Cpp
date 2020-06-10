#include <bits/stdc++.h>
using namespace std;

bool isPossible(int board[][11], int i, int j, int n)
{
    for (int x = 0; x < i; x++)
    {
        if (board[x][j] == 1)
            return false;
    }
    for (int x = 0; x < j; x++)
    {
        if (board[i][x] == 1)
            return false;
    }
    for (int x = i, y = j; x >= 0 and y >= 0; x--, y--)
    {
        if (board[x][y] == 1)
            return false;
    }
    for (int x = i, y = j; x >= 0 and y < n; x--, y++)
    {
        if (board[x][y] == 1)
            return false;
    }
    return true;
}

bool printQueenPos(int board[][11], int i, int n)
{
    if (i == n)
    {
        cout << endl;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }

        return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (isPossible(board, i, j, n))
        {
            board[i][j] = 1;
            if (printQueenPos(board, i + 1, n))
            {
                return true;
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n][11] = {0};
    printQueenPos(arr, 0, n);

    return 0;
}