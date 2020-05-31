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

int getPrimesBetween(ll int *p, ll int a, ll int b)
{
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (p[i])
            count++;
    }
    return count;
}
int computeCumSum(ll int *p)
{
    for (ll int i = 3; i <= 1000000; i++)
    {
        p[i] += p[i - 1];
    }
}
int main()
{
    ll int primes[1000001] = {0};
    int n;
    cin >> n;
    ll int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    primeSieve(primes);
    computeCumSum(primes);
    for (int i = 0; i < n; i++)
    {
        cout << primes[b[i]] - primes[a[i] - 1] << endl;
    }

    return 0;
}