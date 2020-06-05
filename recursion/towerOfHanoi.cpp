/* Using a helper stick (peg), shift all rings from peg A to peg B using peg C.
All rings are initally placed in ascending order, smallest being on top.
No bigger ring can be placed over a smaller ring. */
#include <bits/stdc++.h>
using namespace std;

void move(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;

    move(n - 1, src, helper, dest);
    cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
    move(n - 1, helper, dest, src);
}

int main()
{
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}