#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    cin.get();
    string s;
    getline(cin, s);
    int freq[2] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    char key = freq[0] > freq[1] ? 'a' : 'b';
    for (int i = 0; i < s.length() && k > 0; i++)
    {
        if (s[i] != key)
        {
            s[i] = key;
            k--;
        }
    }
    int len = 0;
    int flen = freq[key - 'a'];
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == key)
        {
            int tlen = 0;
            for (int j = i; j < s.length(); j++)
            {
                if (s[i] != key)
                    break;
                tlen++;
            }
            len = max(len, tlen);
        }
    }
    cout << len;
    return 0;
}