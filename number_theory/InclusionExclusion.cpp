#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll int> primeSieve(int n)
{
    ll int p[n + 1] = {0};
    vector<ll int> primes;
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
ll int fastCount(ll int n)
{
    ll int count = 0;
    while (n != 0)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

ll int countMultiples(ll int n, vector<ll int> p)
{
    ll int sum = 0;
    for (ll int i = 1; i < (1 << p.size()); i++)
    {
        ll int setBits = fastCount(i);
        ll int denom = 1ll;
        for (int j = 0; j < p.size(); j++)
        {
            if (i & (1 << j))
                denom *= p[j];
        }
        if (setBits & 1)
            sum += n / denom;
        else
            sum -= n / denom;
    }
    return sum;
}

int main()
{
    ll int t;
    cin >> t;
    ll int n[t];
    for (ll int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    vector<ll int> primes = primeSieve(20);
    for (ll int i = 0; i < t; i++)
    {
        cout << countMultiples(n[i], primes) << endl;
    }
    return 0;
}