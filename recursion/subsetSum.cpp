#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<vector<ll>> s;
void getSubarrays(ll sum, ll *in, ll *out, ll i, ll j, ll n)
{
    if (sum == 0)
    {
        vector<ll> temp(out, out + j);
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }
    if (i == n or sum < 0)
        return;

    out[j] = in[i];
    getSubarrays(sum - in[i], in, out, i + 1, j + 1, n);
    getSubarrays(sum, in, out, i + 1, j, n);
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
    ll t;
    cin >> t;
    ll temp[n];
    getSubarrays(t, arr, temp, 0, 0, n);
    for (auto it : s)
    {
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << " ";
        }
        cout << endl;
    }
    return 0;
}