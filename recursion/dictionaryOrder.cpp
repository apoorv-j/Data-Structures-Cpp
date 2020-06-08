#include <bits/stdc++.h>
using namespace std;

void largerOrder(string in, string out, int i, int j, string maxStr)
{
    cout << out << " ";
    if (in[i] == '\0')
    {
        out[i] = '\0';
        return;
    }

    for (int k = i; in[k] != '\0'; k++)
    {
        out[j] = in[k];
        largerOrder(in, out, i + 1, j + 1, maxStr);
        maxStr = max(out, maxStr);
    }
}

int main()
{
    string s;
    getline(cin, s);
    string maxStr = s;
    string out(s.length(), 0);
    largerOrder(s, out, 0, 0, maxStr);
    cout << maxStr;
    return 0;
}