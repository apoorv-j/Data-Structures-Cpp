#include <bits/stdc++.h>
using namespace std;

int binaryMedian(int **arr, int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        // Finding the minimum element
        if (arr[i][0] < min)
            min = arr[i][0];

        // Finding the maximum element
        if (arr[i][c - 1] > max)
            max = arr[i][c - 1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        // cout << min << " " << max << " " << mid << endl;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(arr[i], arr[i] + c, mid) - arr[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

// driver program to check above functions
int main()
{
    int n, m;
    cin >> n >> m;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Median is " << binaryMedian(arr, n, m) << endl;
    return 0;
}