#include <bits/stdc++.h>
using namespace std;

int binary_search(int s, int e, int *arr, int key)
{
    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (e - s >= 1)
    {
        if (key < arr[mid])
            return binary_search(s, mid - 1, arr, key);
        else
            return binary_search(mid + 1, e, arr, key);
    }
    return -1;
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
    int key, pos;
    cout << "Enter element to search :";
    cin >> key;
    pos = binary_search(0, n - 1, arr, key);
    if (pos == -1)
    {
        cout << "Element not in array";
    }
    else
    {
        cout << "Element position : " << pos << endl;
    }

    return 0;
}