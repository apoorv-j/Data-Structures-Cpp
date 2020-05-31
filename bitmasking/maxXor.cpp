#include <bits/stdc++.h>
using namespace std;

int getMaxXor(int a, int b)
{
    int x = a ^ b;
    int count = 0;
    while (x > 0)
    {
        count++;
        x = x >> 1;
    }
    int res = 1;
    while (--count > 0)
    {
        res = res << 1;
        res += 1;
    }

    return res;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << getMaxXor(x, y);
    return 0;
}