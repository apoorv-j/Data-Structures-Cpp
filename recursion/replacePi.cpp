/* Replace all occurrences of pi with 3.14 */
#include <bits/stdc++.h>
using namespace std;

void replacePi(char *s, int i)
{
    if (s[i + 1] == '\0')
        return;
    if (s[i] == 'p' and s[i + 1] == 'i')
    {
        int j = i + 2;
        while (s[j] != '\0')
            j++;
        while (j >= i + 2)
        {
            s[j + 2] = s[j];
            j--;
        }
        s[i] = '3';
        s[i + 1] = '.';
        s[i + 2] = '1';
        s[i + 3] = '4';
        return replacePi(s, i + 4);
    }
    return replacePi(s, i + 1);
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    while (n--)
    {
        char s[1000];
        cin.getline(s, 1000);
        replacePi(s, 0);
        cout << s << endl;
    }
    return 0;
}