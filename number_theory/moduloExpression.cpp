#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int fastPower(ll int n, ll int p, ll int m)
{

    ll int res = 1;
    n %= m;
    if (n == 0)
    {
        return 0;
    }
    while (p)
    {
        if (p & 1 > 0)
        {
            res *= n;
            res %= m;
        }
        p >>= 1;
        n *= n;
        n %= m;
    }
    return res;
}
int main()
{

    ll int a, b, c;
    cin >> a >> b >> c;
    ll int x = fastPower(a, b, c);
    cout << x % c;
    return 0;
}
