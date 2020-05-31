#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
bool isPossible(ll int *arr, ll int n, ll int m, ll int mid)
{
    ll int sum = 0;
    for (ll int i = 0; i < n; i++)
    {
        ll int cw = (arr[i] - mid);
        if (cw < 0)
            cw = 0;
        sum += cw;
    }
    if (sum < m)
        return false;
    return true;
}
int main()
{
    ll int n, m;
    cin >> n >> m;
    ll int arr[n];
    ll int maxVal = 0;
    for (ll int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    ll int mid;
    ll int s = 0;
    ll int e = maxVal;
    ll int max_height = e;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (isPossible(arr, n, m, mid))
        {
            max_height = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << max_height;

    return 0;
}