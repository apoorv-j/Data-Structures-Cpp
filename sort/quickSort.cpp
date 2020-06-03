#include <bits/stdc++.h>
using namespace std;

int partition(int s, int e, int *arr)
{
    int pivot = arr[e];
    int i = s - 1;
    int j = s;
    for (; j < e; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[e]);
    return i;
}

void quickSort(int s, int e, int *arr)
{
    if (s >= e)
        return;

    int p = partition(s, e, arr);
    quickSort(s, p - 1, arr);
    quickSort(p + 1, e, arr);
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
    quickSort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}