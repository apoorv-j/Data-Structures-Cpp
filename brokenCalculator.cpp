#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int a[100000] = {0};
    a[0] = 1;
    int len = 1;

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            a[j] *= i;
            a[j] += carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
        }
        while (carry != 0)
        {
            a[len] = carry % 10;
            carry = carry / 10;
            len++;
        }
    }
    for (int i = len - 1; i >= 0; i--)
    {
        cout << a[i];
    }

    return 0;
}