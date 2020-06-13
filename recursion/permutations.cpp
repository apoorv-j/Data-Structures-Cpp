#include <bits/stdc++.h>
using namespace std;
set<string> s;
void getPermutations(string arr, int i)
{
    if (arr[i] == '\0')
    {
        s.insert(arr);
        return;
    }

    for (int j = i; j < arr.length(); j++)
    {
        swap(arr[i], arr[j]);
        getPermutations(arr, i + 1);
        swap(arr[i], arr[j]);
    }
}

int main()
{
    string arr;
    getline(cin, arr);
    getPermutations(arr, 0);
    for (auto it : s)
    {
        cout << it << endl;
    }
    return 0;
}