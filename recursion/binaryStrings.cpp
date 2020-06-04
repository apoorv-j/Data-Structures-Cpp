/* count no of binary strings with no consecutive 1s */
#include <bits/stdc++.h>
using namespace std;

int countBinaryStrings(string s, int i)
{
    if (i == s.length() - 1)
        return 1;

    if (i == s.length())
        return 0;

    if (s[i] == 1 and s[i + 1] == 1)
    {
        return 1 + countBinaryStrings(s, i + 1);
    }

    return countBinaryStrings(s, i + 1);
}

int main()
{
    string s;
    getline(cin, s);
    cout << countBinaryStrings(s, 0);

    return 0;
}