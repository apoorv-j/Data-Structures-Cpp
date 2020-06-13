#include <bits/stdc++.h>
using namespace std;

void moveKnight(int b[][10], int r, int c, int n)
{
    if (r < 0 or c < 0 or r >= n or c >= n or b[r][c] != 1)
        return;

    b[r][c] = 2;
    moveKnight(b, r - 2, c - 1, n);
    moveKnight(b, r - 2, c + 1, n);
    moveKnight(b, r + 2, c - 1, n);
    moveKnight(b, r + 2, c + 1, n);
    moveKnight(b, r + 1, c + 2, n);
    moveKnight(b, r - 1, c + 2, n);
    moveKnight(b, r + 1, c - 2, n);
    moveKnight(b, r - 1, c - 2, n);
}

int main()
{
    int n;
    cin >> n;
    int board[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    moveKnight(board, 0, 0, n);
    int count = 0;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
            if (board[i][j] == 1)
                count++;
        }
        cout << endl;
    }
    cout << count;

    return 0;
}