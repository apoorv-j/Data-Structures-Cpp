#include <iostream>
#include <algorithm>
using namespace std;

int bruteForce(int **a, int r, int c)
{
    int sum = 0;
    for (int li = 0; li < r; li++)
    {
        for (int lj = 0; lj < c; lj++)
        {
            for (int bi = li; bi < r; bi++)
            {
                for (int bj = lj; bj < c; bj++)
                {
                    for (int i = li; i <= bi; i++)
                    {
                        for (int j = lj; j <= bj; j++)
                        {
                            sum += a[i][j];
                        }
                    }
                }
            }
        }
    }
    return sum;
}
int cummSum(int **a, int r, int c)
{
    int sum = 0;

    //compute prefix matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            //update colums
            if (j > 0)
                a[i][j] += a[i][j - 1];

            // cout << a[i][j] << " ";
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            //update rows
            if (i > 0)
                a[i][j] += a[i - 1][j];
            // cout << a[i][j] << " ";
        }
    }

    //calculate sum now
    for (int li = 0; li < r; li++)
    {
        for (int lj = 0; lj < c; lj++)
        {
            for (int bi = li; bi < r; bi++)
            {
                for (int bj = lj; bj < c; bj++)
                {
                    int x = 0, y = 0, z = 0;
                    if (lj > 0)
                        x = a[bi][lj - 1];
                    if (li > 0)
                        y = a[li - 1][bj];
                    if (li > 0 && lj > 0)
                        z = a[li - 1][lj - 1];
                    sum += a[bi][bj] - x - y + z;
                }
                // cout << " sum : " << sum << " " << endl;
            }
        }
    }
    return sum;
}
int sumCode(int **a, int r, int c)
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum += a[i][j] * (c - j) * (r - i) * (i + 1) * (j + 1);
        }
    }
    return sum;
}
int max_sum(int **a, int r, int c)
{
    int sum = 0;
    // update column
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = c - 2; j >= 0; j--)
        {
            a[i][j] += a[i][j + 1];
        }
    }
    // udate rows

    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = c - 1; j >= 0; j--)
        {
            a[i][j] += a[i + 1][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum = max(sum, a[i][j]);
        }
    }
    return sum;
}
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
    int sum = 0;
    // sum = bruteForce(a,r,c);
    // sum = cummSum(a, r, c);
    // sum = sumCode(a, r, c);
    // cout << "Sum of all submatrices is " << sum << endl;
    cout << " Sum of max submatrix is " << max_sum(a, r, c);
    return 0;
}