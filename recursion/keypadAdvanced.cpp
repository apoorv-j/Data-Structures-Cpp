#include <bits/stdc++.h>
using namespace std;
string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void searchName(string s)
{
    for (auto it : searchIn)
    {
        if (it.find(s) != -1)
        {
            cout << it << endl;
        }
    }
}
void keypad(string arr, int i, string out, int j)
{
    if (arr[i] == '\0')
    {
        searchName(out.c_str());
        return;
    }

    for (int k = 0; k < table[arr[i] - '0'].length(); k++)
    {
        out[j] = table[arr[i] - '0'][k];
        keypad(arr, i + 1, out, j + 1);
    }
}

int main()
{
    string arr;
    getline(cin, arr);
    string out(4, 0);
    keypad(arr, 0, out, 0);
    return 0;
}