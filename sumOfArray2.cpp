#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
void getSum(int *a, int *b, int n, int m)
{
    int len = n;
    int s[len];
    n--;
    int carry = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        s[n] = b[i] + a[n] + carry;
        carry = s[n] / 10;
        s[n] = s[n] % 10;
        n--;
    }
    for (int i = n; i >= 0; i--)
    {
        s[i] = a[i] + carry;
        carry = s[i] / 10;
        s[i] = s[i] % 10;
    }
    if (carry > 0)
        cout << carry << ", ";

    for (int i = 0; i < len; i++)
    {
        cout << s[i] << ", ";
    }
    cout << "END";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    if (n >= m)
        getSum(a, b, n, m);
    else
        getSum(b, a, m, n);

    return 0;
}