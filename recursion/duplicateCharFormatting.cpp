#include <bits/stdc++.h>
using namespace std;

void doFormat(char *s, int i)
{
    if (s[i + 1] == '\0' or s[i] == '\0')
        return;
    if (s[i] == s[i + 1])
    {
        int j = i + 2;
        while (s[j] != '\0')
            j++;
        while (j >= i + 1)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[i + 1] = '*';
        return doFormat(s, i + 2);
    }
    doFormat(s, i + 1);
}

void removeDuplicates(char *s, int i)
{
    if (s[i + 1] == '\0')
        return;
    if (s[i] == s[i + 1])
    {
        int j = i + 1;
        while (s[j] != '\0')
        {
            s[j] = s[j + 1];
            j++;
        }
        return removeDuplicates(s, i);
    }
    removeDuplicates(s, i + 1);
}

int main()
{
    char s[10000];
    cin.getline(s, 10000);
    // doFormat(s, 0);
    removeDuplicates(s, 0);
    cout << s;
    return 0;
}