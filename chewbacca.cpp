#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    long long int x;
    cin >> x;

    string s = to_string(x);
    for (int i = 1; i < s.length(); i++)
    {
        int num = s[i] - '0';
        s[i] = min(9 - num, num) + '0';
    }

    int num = s[0] - '0';
    if (num < 9)
        s[0] = min(9 - num, num) + '0';

    cout << s;

    return 0;
}