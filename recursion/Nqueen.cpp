#include <bits/stdc++.h>
using namespace std;

bool isPossible(int board[][11], int i, int j, int n)
{
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
void totalCases(int board[][11], int i, int n, int &count)
{
    if (i == n)
    {
        count++;
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isPossible(board, i, j, n))
        {
            board[i][j] = 1;
            totalCases(board, i + 1, n, count);
            board[i][j] = 0;
        }
    }
}

bool printQueenPos(int board[][11], int i, int n)
{
    if (i == n)
    {

        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;

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
    int count = 0;
    printQueenPos(arr, 0, n);
    totalCases(arr, 0, n, count);
    cout << count;

    return 0;
}