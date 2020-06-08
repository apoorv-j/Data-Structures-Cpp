#include <bits/stdc++.h>
using namespace std;

void keypad(string arr, int i, string *table, string out, int j)
{
    if (arr[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    for (int k = 0; k < table[arr[i] - '0'].length(); k++)
    {
        out[j] = table[arr[i] - '0'][k];
        keypad(arr, i + 1, table, out, j + 1);
    }
}

int main()
{
    string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string arr;
    getline(cin, arr);
    string out(4, 0);
    keypad(arr, 0, table, out, 0);
    return 0;
}