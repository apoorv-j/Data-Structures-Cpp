#include <bits/stdc++.h>
using namespace std;

int getNum(char *a, int i, int n)
{
    if (i == n)
    {
        a[i] = '\0';
        cout << a << " ";
        return 1;
    }

    int c = 0;
    a[i] = 'a';
    c += getNum(a, i + 1, n);
    if (a[i - 1] != 'b')
    {
        a[i] = 'b';
        c += getNum(a, i + 1, n);
    }

    return c;
}

int getNum(int n)
{
    if (n < 1)
        return 0;
    if (n == 1)
    {
        return 2;
    }
    if (n == 2)
        return 3;

    return getNum(n - 1) + getNum(n - 2);
}

int main()
{
    int t;
    cin >> t;
    int n;
    char arr[25] = {0};
    int sno = 1;
    while (t--)
    {
        cin >> n;
        // cout << "#" << sno++ << " : " << getNum(arr, 0, n) << endl;
        cout << "#" << sno++ << " : " << getNum(n) << endl;
    }
    return 0;
}