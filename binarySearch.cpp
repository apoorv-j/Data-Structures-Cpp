#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int binary(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (key == a[m])
        {
            return m;
        }
        else if (key < a[m])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return -1;
}
int main()
{
    int n, x[100], s, e, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    int key, pos;
    cout << "Enter element to search :";
    cin >> key;
    pos = binary(x, n, key);
    if (pos == -1)
    {
        cout << "Element not in array";
    }
    else
    {
        cout << "Element position : " << pos << endl;
    }
    return 0;
}