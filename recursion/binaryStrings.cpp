/* count no of binary strings of length n with no consecutive 1s */
#include <bits/stdc++.h>
using namespace std;

int countBinaryStrings(int n)
{
    if (n == 0)
        return 1;

    int t = n;
    while (t > 2)
    {
        if ((t & 3) == 3)
            return countBinaryStrings(n - 1);
        t >>= 1;
    }

    return countBinaryStrings(n - 1) + 1;
}

int validStrings(int n)
{
    if (n <= 0)
        return 1;

    return validStrings(n - 1) + validStrings(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << countBinaryStrings((1 << n) - 2) << endl;
    cout << validStrings(n) << endl;

    return 0;
}