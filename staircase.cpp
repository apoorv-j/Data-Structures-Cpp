#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int key;
    cin >> key;
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        // cout << a[i][j] << "->";
        if (a[i][j] == key)
        {
            // cout << "\nElement found at: " << i << " " << j << endl;
            cout << '1';
            return 0;
        }
        else if (key > a[i][j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    // cout << "Element not in Matrix" << endl;
    cout << '0';
    return 0;
}