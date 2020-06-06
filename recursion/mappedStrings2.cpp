/* We are given a hashmap which maps all the letters with number.
 Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z.
  Given a number, you have to print all the possible strings */
#include <bits/stdc++.h>
using namespace std;

void getSubarrays(string in, string out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = in[i] - '0';
    out[j] = digit - 1 + 'A';
    getSubarrays(in, out, i + 1, j + 1);

    if (in[i + 1] != '\0')
    {
        int sd = in[i + 1] - '0';
        digit = digit * 10 + sd;
        if (digit <= 26)
        {
            out[j] = digit - 1 + 'A';
            getSubarrays(in, out, i + 2, j + 1);
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    string s2(s.length(), 0);
    getSubarrays(s, s2, 0, 0);
    return 0;
}