/* PROBLEM -
    Given a wall of size 4xN and tiles of size 1,4 and 4,1
    Find number of ways we can fill the wall */

#include <bits/stdc++.h>
using namespace std;

int noOfWays(int n)
{
    if (n <= 3)
        return 1;

    return noOfWays(n - 1) + noOfWays(n - 4);
}
int main()
{
    int n;
    cin >> n;
    cout << noOfWays(n);

    return 0;
}