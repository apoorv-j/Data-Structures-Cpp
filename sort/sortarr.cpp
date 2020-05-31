#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long
void bubble_sort(ll int *a, ll int n)
{
    ll int len = n;
    while (n > 1)
    {
        for (ll int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] < a[i])
            {
                swap(a[i], a[i + 1]);
            }
        }
        n--;
    }
    for (ll int i = 0; i < len; i++)
    {
        cout << a[i] << endl;
    }
}
void insertion_sort(ll int *arr, ll int n)
{
    ll int key = 0, j;
    for (ll int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (ll int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void selection_sort(ll int *arr, ll int n)
{
    ll int srt;
    for (ll int i = 0; i < n - 1; i++)
    {
        srt = i;
        for (ll int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[srt])
            {
                srt = j;
            }
        }
        swap(arr[i], arr[srt]);
        for (ll int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    for (ll int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    ll int n;
    cin >> n;
    ll int a[n];
    for (ll int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // bubble_sort(a, n);
    // insertion_sort(a, n);
    selection_sort(a, n);
    return 0;
}