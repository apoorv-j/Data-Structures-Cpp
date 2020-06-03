#include <bits/stdc++.h>
using namespace std;

int crossCount(int s, int e, int *arr)
{
    //merge and cross count
    int mid = (s + e) / 2;
    int temp[e - s + 1];
    int i = s;
    int j = mid + 1;
    int k = 0;
    int count = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
        {
            count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }
    k = 0;
    while (s <= e)
    {
        arr[s++] = temp[k++];
    }
    return count;
}

int inversionCount(int s, int e, int *arr)
{
    if (s >= e)
        return 0;
    int mid = (s + e) / 2;
    int count1 = inversionCount(s, mid, arr);
    int count2 = inversionCount(mid + 1, e, arr);
    int count3 = crossCount(s, e, arr);
    return count1 + count2 + count3;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(0, n - 1, arr);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return 0;
}