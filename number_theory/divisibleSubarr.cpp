#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll goodArray(ll *a, ll n)
{
    ll count = 0;
    ll freq[n] = {0};
    freq[0] = 1;

    for (ll i = 0; i < n; i++)
    {
        if (i != 0)
            a[i] += a[i - 1];
        a[i] %= n;
        a[i] = (a[i] + n) % n;
        freq[a[i]]++;
    }
    for (ll i = 0; i < n; i++)
    {
        count += freq[i] * (freq[i] - 1) / 2;
    }
    return count;
}

int main()
{
    ll t;
    cin >> t;
    ll n[t];
    ll *arr[t];
    for (ll j = 0; j < t; j++)
    {
        cin >> n[j];
        arr[j] = new ll[n[j]];
        for (ll i = 0; i < n[j]; i++)
        {
            cin >> arr[j][i];
        }
    }

    for (ll i = 0; i < t; i++)
    {

        cout << goodArray(arr[i], n[i]) << endl;
    }
    return 0;
}