#include <iostream>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    int **a = new int *[r];
    for (int i = 0; i < r; i++)
    {
        a[i] = new int[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    int dir = 0; //r=0 d=1 l =2 t=3
    int top = 0, left = 0, right = c - 1, bottom = r - 1;
    // int r=0, c=col;
    while (top <= bottom && left <= right)
    {
        if (dir == 1)
        {
            for (int i = left; i <= right; i++)
                cout << a[bottom][i] << ", ";
            bottom--;
        }
        else if (dir == 0)
        {
            for (int i = top; i <= bottom; i++)
                cout << a[i][left] << ", ";
            left++;
        }
        else if (dir == 3)
        {
            for (int i = right; i >= left; i--)
                cout << a[top][i] << ", ";
            top++;
        }
        else if (dir == 2)
        {
            for (int i = bottom; i >= top; i--)
                cout << a[i][right] << ", ";
            right--;
        }

        dir = (dir + 1) % 4;
    }
    cout << "END";

    return 0;
}