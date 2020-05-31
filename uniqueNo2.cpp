#include <bits/stdc++.h>
using namespace std;

int getBitIndex(int n)
{
    int index = 0;
    while (n)
    {
        if (n & 1 > 0)
        {
            return index;
        }
        index++;
        n >>= 1;
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }
    int index = getBitIndex(res);
    int mask = 1;
    mask <<= index;
    int newRes = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & mask > 0)
            newRes = newRes ^ arr[i];
    }
    res = res ^ newRes;
    cout << min(newRes, res) << " " << max(res, newRes);

    return 0;
}