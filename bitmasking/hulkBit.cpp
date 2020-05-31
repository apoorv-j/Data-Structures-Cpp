#include <iostream>
#include <algorithm>
using namespace std;

int fastCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

int getPower2No(int n)
{
    int k = 0;
    int count = 0;
    for (int i = n; i >= 2; i--)
    {
        if (i & 1 > 0)
            continue;
        count = fastCount(i >> 1);
        // count = __builtin_popcount(i >> 1);
        if (count == 1)
            return i;
    }
    return 0;
}
int getMinSteps(int n)
{
    int steps = 0;
    int k = 0;
    while (n >= 2)
    {
        k = getPower2No(n);
        steps++;
        n -= k;
    }
    steps += n;
    return steps;
}

int main()
{
    int t;
    cin >> t;
    int n[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << getMinSteps(n[i]) << endl;
    }

    return 0;
}