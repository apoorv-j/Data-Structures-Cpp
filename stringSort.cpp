#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
bool compare(string s1, string s2)
{
    if (*s1.begin() == *s2.begin())
    {
        for (int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if (s1[i] != s2[i])
            {
                return s1 < s2;
            }
        }
        return s1.length() > s2.length();
    }

    return s1 < s2;
}
int main()
{
    int n;
    cin >> n;
    cin.get();
    string s[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    sort(s, s + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}