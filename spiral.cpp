#include <iostream>
using namespace std;

int main()
{
    int a[][4] = {1, 4, 7, 10, 2, 5, 8, 11, 3, 6, 9, 12};
    int row = 3, col = 4;
    int dir = 0; //r=0 d=1 l =2 t=3
    int top = 0, left = 0, right = col - 1, bottom = row - 1;
    // int r=0, c=col;
    while (top <= bottom && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
                cout << a[top][i] << " ";
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
                cout << a[i][right] << " ";
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                cout << a[bottom][i] << " ";
            bottom--;
        }
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }

        dir = (dir + 1) % 4;
        // cout << "\n r: " << right << " l: " << left << " t: " << top << " b: " << bottom << endl;
        // cout << "Direc : " << dir << endl;
    }

    return 0;
}