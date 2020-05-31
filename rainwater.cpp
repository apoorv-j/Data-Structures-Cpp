#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int water = 0;

    int left[n];
    int right[n];
    int max_left = a[0];
    int max_right = a[n - 1];
    left[0] = max_left;
    right[n - 1] = max_right;
    for (int i = 1; i < n; i++)
    {
        max_left = max(max_left, a[i]);
        left[i] = max_left;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        max_right = max(max_right, a[i]);
        right[i] = max_right;
    }

    for (int i = 1; i < n - 1; i++)
    {
        water += min(left[i], right[i]) - a[i];
    }
    cout << water;
    return 0;
}