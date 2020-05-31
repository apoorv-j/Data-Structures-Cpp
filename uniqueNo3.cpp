#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int a[64] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int j = 0;
        while (x)
        {
            if (x & 1 > 0)
                a[j]++;
            x = x >> 1;
            j++;
        }
    }
    int res = 0;
    //mod 3 and convert to binary

    for (int i = 0; i < 64; i++)
    {
        a[i] = a[i] % 3;
        if (a[i] > 0)
            res += pow(2, i);
    }

    cout << res;

    return 0;
}