#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.get();
    string s[t];
    for (int i = 0; i < t; i++)
        getline(cin, s[i]);

    for (int i = 0; i < t; i++)
    {
        string s1 = strtok((char *)s[i].c_str(), " ");
        string s2 = strtok(NULL, " ");
        for (int j = 0; j < s1.length(); j++)
        {
            if (s1[j] != s2[j])
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }
    return 0;
}