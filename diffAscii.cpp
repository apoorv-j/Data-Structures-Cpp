#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int i;
    for (i = 1; i < s.length(); i++)
    {
        cout << s[i - 1];
        cout << s[i] - s[i - 1];
    }
    cout << s[i - 1];

    return 0;
}