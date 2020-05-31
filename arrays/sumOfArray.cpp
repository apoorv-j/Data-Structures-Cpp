#include <iostream>
#include <algorithm>
using namespace std;

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

    int i = n - 1, j = m - 1;
    int carry = 0;

    int k = max(m, n);
    int s[k] = {0};
    int t = k - 1;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--];
        if (j >= 0)
            sum += b[j--];
        carry = sum / 10;

        s[t--] = (sum % 10);
    }

    if (carry > 0)
        cout << carry << ", ";

    for (int i = 0; i < k; i++)
    {
        cout << s[i] << ", ";
    }
    cout << "END";

    return 0;
}