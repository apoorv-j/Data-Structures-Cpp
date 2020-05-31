#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

bool isPalindrome(string &s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
int main()
{
    int n;
    cin >> n;
    string arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.append(to_string(x));
    }
    cout << arr;
    cout << boolalpha << isPalindrome(arr);
    return 0;
}