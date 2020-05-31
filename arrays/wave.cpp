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
    for (int j = 0; j < c; j++)
    {
        if (j % 2 == 0)
            for (int i = 0; i < r; i++)
                cout << a[i][j] << ",";

        else
            for (int i = r - 1; i >= 0; i--)
                cout << a[i][j] << ",";
    }
    cout << "END";
    return 0;
}