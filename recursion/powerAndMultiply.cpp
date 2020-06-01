#include <bits/stdc++.h>
using namespace std;

int getPowerRecursive(int n, int p)
{
    if (p == 0)
        return 1;

    return n * getPowerRecursive(n, p - 1);
}
int multiply(int a, int b)
{
    if (b == 0)
        return 0;

    return a + multiply(a, b - 1);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getPowerRecursive(a, b);
    cout << endl;
    cout << multiply(a, b) << endl;
    return 0;
}