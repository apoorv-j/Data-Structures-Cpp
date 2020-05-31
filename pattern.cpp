#include <iostream>
#include <algorithm>
using namespace std;

void printPattern(int i, int n)
{
    int spaces = n - i;
    while (spaces != 0)
    {
        cout << "  ";
        spaces--;
    }
    for (int j = i; j >= 0; j--)
    {
        cout << j << " ";
        if (j == 0)
        {
            for (int k = 1; k <= i; k++)
            {
                cout << k << " ";
            }
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        printPattern(i, n);
    }
    for (int i = 1; i <= n; i++)
    {
        printPattern(i, n);
    }

    return 0;
}