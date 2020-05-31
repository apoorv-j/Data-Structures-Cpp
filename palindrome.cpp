#include <iostream>
#include <string.h>
using namespace std;

bool isPalindrome(int *a, int st, int end)
{
    if (st == end)
        return true;

    if (a[st] != a[end])
        return false;

    if (st < end)
    {
        return isPalindrome(a, st + 1, end - 1);
    }

    return true;
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

    cout << boolalpha << isPalindrome(a, 0, n - 1);
    return 0;
}