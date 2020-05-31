#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
void compress(string s)
{
    int freq[127] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }

    for (int i = 0; i < 126; i++)
    {
        if (freq[i] > 0)
        {
            cout << (char)i << freq[i];
        }
    }
}
int main()
{
    string s;
    getline(cin, s);
    compress(s);

    return 0;
}