/* Given N and K. 
    Find the number of a person can climb a ladder of size n 
    if he can take climb k steps at a time 
*/
#include <bits/stdc++.h>
using namespace std;

int ladderSol(int n, int k)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;

    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += ladderSol(n - i, k);
    }
    return sum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << ladderSol(n, k) << endl;

    return 0;
}