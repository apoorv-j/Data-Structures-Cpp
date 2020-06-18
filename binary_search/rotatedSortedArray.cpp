#include <bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[s] <= arr[mid])
        {
            if (key >= arr[s] and key <= arr[mid])
                e = mid - 1;

            else
                s = mid + 1;
        }
        else
        {
            if (key >= arr[mid] and key <= arr[e])
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int find_pivot(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] > arr[mid + 1])
            return mid;
        if (arr[s] <= arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

int main()
{
    int n, s, e, m;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int key, pos;
    cout << "Enter element to search :";
    cin >> key;

    pos = binary_search(x, n, key);
    if (pos == -1)
    {
        cout << "Element not in array";
    }
    else
    {
        cout << "Element position : " << pos << endl;
    }
    // cout << find_pivot(x, n);

    return 0;
}