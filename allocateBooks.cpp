#include <iostream>
#include <algorithm>
using namespace std;

bool checkMinPageCondition(int *arr, int n, int m, int mid)
{
    int j = 0;
    int sum = 0;
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            s++;
            sum = arr[i];
            if (s > m)
                return false;
        }
    }

    return 1;
}
int getMinPages(int *arr, int n, int m)
{
    int s = arr[n - 1];
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }
    int mid;
    int pages = e;

    while (s <= e)
    {
        mid = (s + e) / 2;
        // cout << pages << " ";
        if (checkMinPageCondition(arr, n, m, mid))
        {

            pages = min(pages, mid);
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return pages;
}
int main()
{
    int t;
    cin >> t;
    int n[t], m[t];
    int *arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i] >> m[i];
        arr[i] = new int[n[i]];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        // sort(arr[i], arr[i] + n[i]);
        if (n[i] < m[i])
        {
            cout << "-1";
            break;
        }
        cout << getMinPages(arr[i], n[i], m[i]) << endl;
    }
    return 0;
}