#include <bits/stdc++.h>
using namespace std;

void dictionaryOrderLarger(string arr, int i, set<string> &s, string og)
{
    if (arr[i] == '\0')
    {
        if (arr > og)
            s.insert(arr);
        return;
    }

    for (int j = i; j < arr.length(); j++)
    {
        swap(arr[i], arr[j]);
        dictionaryOrderLarger(arr, i + 1, s, og);
        swap(arr[i], arr[j]);
    }
}

int main()
{
    string arr;
    getline(cin, arr);
    set<string> large;
    dictionaryOrderLarger(arr, 0, large, arr);
    for (auto it : large)
    {
        cout << it << endl;
    }
    return 0;
}