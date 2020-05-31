#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> primeSieve(ll int n)
{
    ll int p[n] = {0};
    vector<int> primes;
    primes.push_back(2);
    for (ll int i = 3; i <= n; i += 2)
        p[i] = 1;
    for (ll int i = 3; i <= n; i += 2)
    {
        if (p[i])
        {
            primes.push_back(i);
            for (ll int j = i * i; j <= n; j += i)
                p[j] = 0;
        }
    }
    return primes;
}
vector<int> getFactors(vector<int> &p, ll int n)
{
    vector<int> factors;
    for (int i = 0; i < p.size() && p.at(i) * p.at(i); i++)
    {
        if (n % p[i] == 0)
        {
            while (n % p[i])
                n = n / p[i];
            factors.push_back(p[i]);
        }
    }
    if (n != 1)
    {
        factors.push_back(n);
    }
    return factors;
}
int main()
{
    vector<int> primes = primeSieve(1000000);
    int t;
    cin >> t;
    ll int n[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        vector<int> factors = getFactors(primes, n[i]);
        for (auto it : factors)
            cout << it << " ";
        factors.clear();
    }

    return 0;
}