#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;
    int res = 1;
    while (p)
    {
        if (p & 1 > 0)
        {
            res *= n;
        }
        p >>= 1;
        n *= n;
    }
    cout << res;
    return 0;
}