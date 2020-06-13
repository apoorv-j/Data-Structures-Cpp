#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool getSubarrays(ll *in, ll sum, ll i, ll n)
{
    if (i + 1 == n)
    {
        if ((sum + in[i]) == 0)
            return true;
        return false;
    }
    if ((sum + in[i]) == 0)
        return true;
    return getSubarrays(in, sum, i + 1, n) or getSubarrays(in, sum + in[i], i + 1, n);
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (getSubarrays(arr, 0, 0, n))
            cout << "Yes";

        else
            cout << "No";

        cout << endl;
    }
    return 0;
}