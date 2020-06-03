#include <bits/stdc++.h>
using namespace std;

int fastPower(int n, int p)
{
    if (p == 0)
        return 1;

    if (p & 1)
    {
        return n * fastPower(n * n, p >> 1);
    }

    return fastPower(n * n, p >> 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << fastPower(a, b);
    cout << endl;
    return 0;
}