#include <bits/stdc++.h>
using namespace std;

int getSubarrays(string in, string out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        return 1;
    }
    int c1 = getSubarrays(in, out, i + 1, j);
    out[j] = in[i];
    int c2 = getSubarrays(in, out, i + 1, j + 1);
    return c1 + c2;
}
int main()
{
    string s;
    getline(cin, s);
    string s2(s.length(), 0);
    cout << getSubarrays(s, s2, 0, 0);
    return 0;
}