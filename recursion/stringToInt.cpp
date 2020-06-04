#include <bits/stdc++.h>
using namespace std;

int stringToInt(string s, int n)
{
    if (n == 0)
        return 0;

    return stringToInt(s, n - 1) * 10 + (s[n - 1] - '0');
}

int main()
{
    string s;
    getline(cin, s);
    int num = stringToInt(s, s.length());
    cout << num << endl;
    return 0;
}