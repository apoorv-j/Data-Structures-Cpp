#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isSorted(ll int *arr, ll int n)
{
    if (n == 1)
        return true;

    if (arr[0] <= arr[1] && isSorted(arr + 1, n - 1))
        return true;

    return false;
}
int main()
{
    ll int n;
    cin >> n;
    ll int arr[n];
    for (ll int i = 0; i < n; i++)
        cin >> arr[i];
    cout << boolalpha << isSorted(arr, n);

    return 0;
}