#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
bool isPossible(ll n, ll m, ll x, ll y, ll mid)
{
    if (x * mid <= m + (n - mid) * y)
        return true;

    return false;
}
int main()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    ll s = 0;
    ll e = n;
    ll mid;
    ll res = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        // cout << "mid: " << mid << endl;
        if (isPossible(n, m, x, y, mid))
        {
            res = max(res, mid);
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }
    cout << res;

    return 0;
}