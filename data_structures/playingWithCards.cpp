#include <bits/stdc++.h>
using namespace std;
#define ll long long

deque<ll> primes;
void primeSieve()
{
    ll p[100001] = {0};
    primes.push_back(2);
    for (ll i = 3; i <= 100000; i += 2)
        p[i] = 1;
    for (ll i = 3; i <= 100000; i += 2)
    {
        if (p[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= 100000; j += i)
                p[j] = 0;
        }
    }
}

int main()
{
    ll n, q;
    cin >> n >> q;
    stack<ll> a[q + 1];
    primeSieve();
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        a[0].push(temp);
    }
    stack<ll> b[q];
    for (ll i = 1; i <= q; i++)
    {
        ll prime = primes[i - 1];
        while (!a[i - 1].empty())
        {
            ll x = a[i - 1].top();
            a[i - 1].pop();
            if (x % prime == 0)
                b[i - 1].push(x);
            else
                a[i].push(x);
        }
    }
    for (ll i = 0; i < q; i++)
    {
        while (!b[i].empty())
        {
            cout << b[i].top() << endl;
            b[i].pop();
        }
    }
    while (!a[q].empty())
    {
        cout << a[q].top() << endl;
        a[q].pop();
    }

    return 0;
}