#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    // cout << __gcd(n1, n2);
    cout << gcd(n1, n2);
    return 0;
}