/* PROBLEM -
    Given a wall of size MxN and tiles of size 1,m and m,1
    Find number of ways we can fill the wall */

#include <bits/stdc++.h>
using namespace std;

int noOfWays(int n, int m)
{
    if (n <= m - 1)
        return 1;

    return (noOfWays(n - 1, m) % 1000000007 + noOfWays(n - m, m) % 1000000007) % 1000000007;
}
int main()
{
    int t;
    cin >> t;
    int n, m;

    while (t--)
    {
        cin >> n >> m;
        cout << noOfWays(n, m) << endl;
    }

    return 0;
}