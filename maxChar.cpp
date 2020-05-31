#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    // cout << s;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    int count = 0;
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > count)
        {
            count = freq[i];
            ch = i + 'a';
        }
    }
    cout << ch;
    return 0;
}