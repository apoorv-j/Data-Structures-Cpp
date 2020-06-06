/* We are given a hashmap which maps all the letters with number.
 Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z.
  Given a number, you have to print all the possible strings */
#include <bits/stdc++.h>
using namespace std;

char getLetter(string s)
{
    int num = stoi(s);
    return num - 1 + 'A';
}

bool isPossible(string s)
{
    if (stoi(s) <= 26)
        return true;
    return false;
}

void getSubarrays(string in, string out, int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    out[j] = getLetter(in.substr(i, 1));
    getSubarrays(in, out, i + 1, j + 1);

    if (in[i + 1] != '\0' and isPossible(in.substr(i, 2)))
    {
        out[j] = getLetter(in.substr(i, i + 2));
        getSubarrays(in, out, i + 2, j + 1);
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