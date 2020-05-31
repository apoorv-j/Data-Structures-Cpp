#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
bool isPossible(int **arr, int n, int m, int mid, int median)
{
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = new int[m];
        for (int j = n - 1; j >= 0; j--)
        {
            cin >> a[i][j];
        }
    }
    int len = m * n - 1;

    int median = len / 2;
    int s = INTMAX_MAX;
    int e = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        s = min(s, a[i][0]);
        e = max(e, a[i][m - 1]);
    }
    int mid;
    int ans;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (isPossible(a, n, m, mid, median))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
}