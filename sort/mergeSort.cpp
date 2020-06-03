#include <bits/stdc++.h>
using namespace std;

void merge(int s, int e, int *arr)
{
    int mid = (s + e) / 2;
    int temp[e - s + 1];
    int i = s;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
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
}

void mergeSort(int s, int e, int *arr)
{
    if (s >= e)
        return;
    int mid = (s + e) / 2;
    mergeSort(s, mid, arr);
    mergeSort(mid + 1, e, arr);
    merge(s, e, arr);
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
    mergeSort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}