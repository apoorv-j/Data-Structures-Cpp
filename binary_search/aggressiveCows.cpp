#include <iostream>
#include <algorithm>
using namespace std;
int getSpaceBtCows(int *a, int n, int c)
{
    int s = 0;
    int e = a[n - 1];
    int mid = (s + e) / 2;
    int ans = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        int first = a[0];
        int j = 1;
        for (int i = 1; i < n && j < c; i++)
        {
            if ((a[i] - first) >= mid)
            {
                j++;
                first = a[i];
            }
        }
        if (j == c)
        {
            ans = max(ans, mid);
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    int n[t], c[t];
    int *arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> c[i];
        arr[i] = new int[n[i]];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        sort(arr[i], arr[i] + n[i]);
        cout << getSpaceBtCows(arr[i], n[i], c[i]) << endl;
    }

    return 0;
}