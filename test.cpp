#include <bits/stdc++.h>
using namespace std;

int fastCount(int n)
{
    int c = 0;
    while (n)
    {
        n = n & n - 1;
        c++;
    }
    return c;
}
void printPattern(int n)
{
}
int main()
{
    int n;
    cin >> n;
    printPattern(n);
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // for (int i = 0; i < n; i++)
    //     cout << fastCount(a[i]) << endl;
    return 0;
}