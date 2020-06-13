#include <bits/stdc++.h>
using namespace std;

void generateBrackets(int n, int o, int c, char *s, int i)
{
    if (i == 2 * n)
    {
        s[i] = '\0';
        cout << s << endl;
        return;
    }

    if (c < o)
    {
        s[i] = ')';
        generateBrackets(n, o, c + 1, s, i + 1);
    }
    if (o < n)
    {
        s[i] = '(';
        generateBrackets(n, o + 1, c, s, i + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    char s[(2 * n) + 1] = {0};
    generateBrackets(n, 0, 0, s, 0);
    return 0;
}