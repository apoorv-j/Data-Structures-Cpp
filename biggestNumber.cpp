#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool comparator(int x, int y)
{
    string s1 = to_string(x);
    string s2 = to_string(y);
    return s1 + s2 > s2 + s1;
}

int main()
{
    int t;
    cin >> t;
    int n[t];
    int *a[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
        a[i] = new int[n[i]];
        for (int k = 0; k < n[i]; k++)
            cin >> a[i][k];
    }
    for (int i = 0; i < t; i++)
    {
        sort(a[i], a[i] + n[i], comparator);
        for (int j = 0; j < n[i]; j++)
            cout << a[i][j];
        cout << endl;
    }

    return 0;
}