#include <iostream>
#include <algorithm>
using namespace std;

int getBitonicLength(int *a, int n)
{
    int left[n], right[n];
    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }

    int length = 0;
    for (int i = 0; i < n; i++)
    {
        length = max(length, left[i] + right[i] - 1);
    }
    return length;
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
        cout << getBitonicLength(a[i], n[i]) << endl;
    }
    return 0;
}