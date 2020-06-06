/* Take as input str, a string. 
Write a recursive function which moves all ‘x’ from the string to its end. */
#include <bits/stdc++.h>
using namespace std;

void moveXtoEnd(char *s, int i, int n)
{

    if (i == n)
        return;
    if (s[i] == 'x')
    {
        int j = i;
        while (j < n)
        {
            s[j] = s[j + 1];
            j++;
        }
        s[n] = 'x';
        return moveXtoEnd(s, i, n - 1);
    }
    moveXtoEnd(s, i + 1, n);
}

int main()
{
    char s[10000];
    cin.getline(s, 10000);
    moveXtoEnd(s, 0, strlen(s) - 1);
    cout << s;
    return 0;
}