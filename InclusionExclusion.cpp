#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll int> primeSieve()
{
    ll int p[1000000000000000000] = {0};
    vector<ll int> primes;
    for (ll int i = 3; i <= 1000000000000000000; i += 2)
        p[i] = 1;
    for (ll int i = 3; i <= 1000000000000000000; i += 2)
    {
        if (p[i])
        {
            primes.push_back(p[i]);
            for (ll int j = i * i; j <= 1000000000000000000; j += i)
                p[j] = 0;
        }
    }
    // p[2] = 1;
    // p[1] = p[0] = 0;
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
    for (ll int i = 1; i < 1 << n; i++)
    {
        for (auto it : p)
        {
            if (i % it == 0)
            {
                ll int bits = fastCount(i);
                cout << bits << " ";
                if (bits % 2 == 0)
                    sum -= bits;
                else
                    sum += bits;
            }
        }
    }
    cout << endl;
    return sum;
}

int main()
{
    // ll int t;
    // cin >> t;
    // ll int n[t];
    // for (ll int i = 0; i < t; i++)
    // {
    //     cin >> n[i];
    // }
    vector<ll int> primes = primeSieve();
    // for (ll int i = 0; i < t; i++)
    // {
    //     cout << countMultiples(n[i],primes) << endl;
    // }
    for (auto it : primes)
        cout << it << " ";
    return 0;
}