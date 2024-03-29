#include <bits/stdc++.h>
using namespace std;
#define ll long long
void primeSieve(ll int *p)
{
    for (ll int i = 3; i <= 1000000; i += 2)
        p[i] = 1;
    for (ll int i = 3; i <= 1000000; i += 2)
    {
        if (p[i])
            for (ll int j = i * i; j <= 1000000; j += i)
                p[j] = 0;
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

ll int getPrimesBetween(ll int *p, ll int a, ll int b)
{
    ll int count = 0;
    for (ll int i = a; i <= b; i++)
    {
        if (p[i])
            count++;
    }
    return count;
}

void computeCumSum(ll int *p)
{
    for (ll int i = 3; i <= 1000000; i++)
    {
        p[i] += p[i - 1];
    }
}
int main()
{
    ll int primes[1000005] = {0};
    ll int n;
    cin >> n;
    ll int a[n], b[n];
    for (ll int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    primeSieve(primes);
    // computeCumSum(primes);
    for (ll int i = 0; i < n; i++)
    {
        // cout << primes[b[i]] - primes[a[i] - 1] << endl;
        cout << getPrimesBetween(primes, a[i], b[i]) << endl;
    }

    return 0;
}