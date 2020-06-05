#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll firstOcc(ll *arr, ll n, ll key)
{
    if (arr[0] == key)
        return 0;

    if (n == 0)
        return -1;

    ll i = firstOcc(arr + 1, n - 1, key);

    if (i == -1)
        return -1;

    else
        return i + 1;
}
ll lastOcc(ll *arr, ll n, ll key)
{
    n--;
    if (n < 0)
        return -1;
    if (arr[n] == key)
        return n;
    return lastOcc(arr, n, key);
}
void allOcc(ll *arr, ll n, ll i, ll key)
{
    if (i == n)
        return;

    if (arr[i] == key)
        cout << i << " ";

    allOcc(arr, n, i + 1, key);
}
int allIndices(ll *arr, ll n, ll i, ll key, ll *out, int j)
{
    if (i == n)
    {
        return j;
    }

    if (arr[i] == key)
    {
        out[j] = i;
        return allIndices(arr, n, i + 1, key, out, j + 1);
    }

    return allIndices(arr, n, i + 1, key, out, j);
}
int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll key;
    cin >> key;
    ll out[n] = {0};
    int count = allIndices(arr, n, 0, key, out, 0);

    for (int i = 0; i < count; i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}