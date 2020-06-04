#include <bits/stdc++.h>
using namespace std;

void move(int n, char src, char dest, char helper)
{
    if (n == 0)
        return;

    move(n - 1, src, helper, dest);
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    move(n - 1, helper, dest, src);
}

int main()
{
    int n;
    cin >> n;
    move(n, 'A', 'C', 'B');
    return 0;
}