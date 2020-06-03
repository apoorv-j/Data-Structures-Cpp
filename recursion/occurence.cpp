#include <bits/stdc++.h>
using namespace std;

int firstOcc(int *arr, int n, int key)
{
    if (arr[0] == key)
        return 0;

    if (n == 0)
        return -1;

    int i = firstOcc(arr + 1, n - 1, key);

    if (i == -1)
        return -1;

    else
        return i + 1;
}
int lastOcc(int *arr, int n, int key)
{
    n--;
    if (n < 0)
        return -1;
    if (arr[n] == key)
        return n;
    return lastOcc(arr, n, key);
}
void allOcc(int *arr, int n, int i, int key)
{
    if (i == n)
        return;

    if (arr[i] == key)
        cout << i << " ";

    allOcc(arr, n, i + 1, key);
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
    int key;
    cin >> key;
    cout << "First Occurence :" << firstOcc(arr, n, key) << endl;
    cout << "Last Occurence :" << lastOcc(arr, n, key) << endl;
    cout << "All Occurences :";
    allOcc(arr, n, 0, key);
    cout << endl;

    return 0;
}