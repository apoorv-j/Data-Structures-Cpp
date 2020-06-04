/* Give N, n friends and bikes
    each guy can go as single or as a couple
    find no of ways in which N friends can go to party
 */
#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
    if (n == 0 or n == 1)
        return 1;
    if (n < 0)
        return 0;

    return f(n - 1) + (n - 1) * f(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}