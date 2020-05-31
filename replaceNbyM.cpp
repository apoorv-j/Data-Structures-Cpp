// Given no.s N and M, replace the digits from i to j in N by M

#include <iostream>
#include <algorithm>
using namespace std;

int clearRange(int n, int i, int j)
{
    int a = (~0) << j;
    int b = (2 ^ i) - 1;
    int mask = a | b;
    return n & mask;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int i, j;
    cin >> i >> j;
    n = clearRange(n, i, j);
    m = m << i;
    n = n | m;
    cout << n << endl;

    return 0;
}